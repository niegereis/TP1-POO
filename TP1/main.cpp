#include <stdio.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "funcoesAuxiliares.h"
#include "imovel.h"

using namespace std;
using namespace FuncoesAuxiliares;

int main() {
  cout << fixed << setprecision(2);
  string arquivoImoveis = "dataBaseImoveis.txt", linha;
  ifstream arquivo(arquivoImoveis);
  vector<Imovel*> listaDeImoveis;

  if (!arquivo.is_open()) {
    cout << "Erro ao abrir arquivo de imóveis!" << endl;
    return 1;
  }

  int id = 1;
  while (getline(arquivo, linha)) {
    Imovel* imovel = criarImovelPelaLinha(linha, id);
    listaDeImoveis.push_back(imovel);
    id++;
  }
  arquivo.close();

  int opcao;
  do {
    cout << "------------------------------------------------------------------"
            "-----------------------"
         << endl;
    cout << "0 - Sair do programa." << endl;
    cout << "1 - Verifica se propietário possui algum imóvel." << endl;
    cout << "2 - Obtêm os imóveis abaixo ou igual a um valor." << endl;
    cout << "3 - Obtêm os imóveis que possuem um número maior ou igual a "
            "quantidade de quartos."
         << endl;
    cout << "4 - Obtêm um lista de imóveis pelo tipo ordenados pelo valor "
            "crescente."
         << endl;
    cout << "5 - Obtêm um lista de imóveis pela cidade e ordena pelo valor "
            "decrescente."
         << endl;
    cout << "6 - Obtêm lista de imóveis pelo tipo(usando tabela hash)." << endl;
    cout << "7 - Obtêm lista de imóveis pelo proprierário." << endl;
    cout << "8 - Imprime na tela ou salva em um arquivo." << endl;
    cout << "------------------------------------------------------------------"
            "-----------------------"
         << endl;
    cout << "Digite a opção desejada: ";
    cin >> opcao;

    limpaBuffer();

    if (opcao == 1) {
      string proprietario;
      cout << "Digite o nome do proprietário que você deseja buscar: ";
      getline(cin, proprietario);

      if (ehProprietario(listaDeImoveis, proprietario)) {
        cout << "É proprietário!" << endl;
      } else {
        cout << "Não é proprietário!" << endl;
      }
    }

    else if (opcao == 2) {
      float valorBuscado;
      cout << "Digite pelo valor do imóvel que você deseja buscar: ";
      cin >> valorBuscado;
      vector<Imovel*> listaDeImoveisValorBuscado =
          obterListaDeImoveisPeloValor(listaDeImoveis, valorBuscado);
      if (!listaDeImoveisValorBuscado.empty())
        imprimeListaOuSalvaEmArquivo(listaDeImoveisValorBuscado, "imprime");
      else
        cout << "Não existe imovel no intervalo de valor buscado!" << endl;
      limpaBuffer();
    }

    else if (opcao == 3) {
      int qtQuartosBuscado;
      cout << "Digite pela quantidade de quartos do imóvel que você deseja "
              "buscar: ";
      cin >> qtQuartosBuscado;
      vector<Imovel*> listaDeImoveisQuartosBuscado =
          obterListaDeImoveisPelaQuantidadeQuartos(listaDeImoveis,
                                                   qtQuartosBuscado);
      if (!listaDeImoveisQuartosBuscado.empty())
        imprimeListaOuSalvaEmArquivo(listaDeImoveisQuartosBuscado, "imprime");
      else
        cout << "Não existe imovel no intervalo de quartos buscado!" << endl;
    }

    else if (opcao == 4) {
      string tipoImovel;
      cout << "Digite pelo tipo do imóvel que você deseja buscar: ";
      getline(cin, tipoImovel);
      vector<Imovel*> listaDeImoveisTipoDoImovelBuscado =
          obterListaDeImoveisPeloTipoDoImovel(listaDeImoveis, tipoImovel);
      if (!listaDeImoveisTipoDoImovelBuscado.empty())
        imprimeListaOuSalvaEmArquivo(listaDeImoveisTipoDoImovelBuscado,
                                     "imprime");
      else
        cout << "Não existe imovel do tipo buscado!" << endl;
    }

    else if (opcao == 5) {
      string cidade;
      cout
          << "Digite pela cidade em que está o imóvel que você deseja buscar: ";
      getline(cin, cidade);
      vector<Imovel*> listaDeImoveisCidadeDoImovelBuscado =
          obterListaDeImoveisPelaCidadeDoImovel(listaDeImoveis, cidade);
      if (!listaDeImoveisCidadeDoImovelBuscado.empty())
        imprimeListaOuSalvaEmArquivo(listaDeImoveisCidadeDoImovelBuscado,
                                     "imprime");
      else
        cout << "Não existe imovel da cidade buscada!" << endl;
    }

    else if (opcao == 6) {
      string tipoBuscado;
      cout << "Digite pelo tipo de imóvel que você deseja: ";
      getline(cin, tipoBuscado);
      map<string, vector<Imovel*>> tabelaDeImoveis = obterTabelaPeloTipo(listaDeImoveis);
      if (!tabelaDeImoveis.empty())
        imprimeListaOuSalvaEmArquivo(tabelaDeImoveis[tipoBuscado], "imprime");
      else
        cout << "Não existe nenhum imóvel do tipo buscado!" << endl;
    }

    else if (opcao == 7) {
      string proprietarioBuscado;
      cout << "Digite pelo proprietário que é dono do imóvel que você deseja "
              "buscar : ";
      getline(cin, proprietarioBuscado);
      vector<Imovel*> listaDeImoveisProprietarioDoImovelBuscado =
          obterListaDeImoveisPeloProprietarioDoImovel(listaDeImoveis,
                                                      proprietarioBuscado);
      if (!listaDeImoveisProprietarioDoImovelBuscado.empty())
        imprimeListaOuSalvaEmArquivo(listaDeImoveisProprietarioDoImovelBuscado,
                                     "imprime");
      else
        cout << "Não existe imovel do proprietário buscado!" << endl;
    }

    else if (opcao == 8) {
      string escolhaDoUsuario;
      cout << "Digite 'imprime' para imprimir no terminal ou 'arquivo' para "
              "salvar os dados dos imóveis em um arquivo saida.txt:";
      getline(cin, escolhaDoUsuario);
      imprimeListaOuSalvaEmArquivo(listaDeImoveis, escolhaDoUsuario);
    }
    if (opcao != 0) {
      cout << "Digite enter para continuar...";
      getchar();
      system("clear");
    }
  } while (opcao != 0);

  for (Imovel* imovel : listaDeImoveis) {
    delete imovel;
  }

  return 0;
}