#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "imovel.h"

using namespace std;

void imprimeLista(vector<Imovel*> listaDeImoveis, string escolhaUsuario) {
  string nomeArquivoSaida;
  if (escolhaUsuario == "imprime") {
    for (Imovel* imovel : listaDeImoveis) {
      Casa* casa = dynamic_cast<Casa*>(imovel);
      if (casa != nullptr) cout << *casa << endl;

      Apartamento* apartamento = dynamic_cast<Apartamento*>(imovel);
      if (apartamento != nullptr) cout << *apartamento << endl;

      Chacara* chacara = dynamic_cast<Chacara*>(imovel);
      if (chacara != nullptr) cout << *chacara << endl;
    }
  } else if (escolhaUsuario == "arquivo") {
    nomeArquivoSaida = "saida.txt";
    ofstream arquivoDeSaida(nomeArquivoSaida);
    if (arquivoDeSaida.is_open()) {
      for (Imovel* imovel : listaDeImoveis) {
        Casa* casa = dynamic_cast<Casa*>(imovel);
        if (casa != nullptr) arquivoDeSaida << *casa << endl;

        Apartamento* apartamento = dynamic_cast<Apartamento*>(imovel);
        if (apartamento != nullptr) arquivoDeSaida << *apartamento << endl;

        Chacara* chacara = dynamic_cast<Chacara*>(imovel);
        if (chacara != nullptr) arquivoDeSaida << *chacara << endl;
      }
      arquivoDeSaida.close();
      cout << "Os dados foram salvos no arquivo " << nomeArquivoSaida << endl;
    } else {
      cerr << "Erro ao abrir o arquivo " << nomeArquivoSaida << endl;
    }
  }
}

bool ehProprietario(vector<Imovel*> listaImoveis, string proprietario) {
  for (Imovel* imovel : listaImoveis) {
    if (imovel->getPropietario() == proprietario) return true;
  }
  return false;
}

Imovel* criarImovelPelaLinha(string linha) {
  istringstream palavra(linha);
  string valor, numero, quartos, banheiros, tipo, proprietario, rua, bairro,
      cidade;

  getline(palavra, tipo, ';');
  getline(palavra, valor, ';');
  getline(palavra, proprietario, ';');
  getline(palavra, rua, ';');
  getline(palavra, bairro, ';');
  getline(palavra, cidade, ';');
  getline(palavra, numero, ';');
  getline(palavra, quartos, ';');
  getline(palavra, banheiros, ';');

  if (tipo == "casa") {
    int andares;
    bool salaJantar;
    palavra >> andares;
    palavra >> salaJantar;
    Casa* casa = new Casa(andares, salaJantar, 0, stoi(numero), stoi(quartos),
                          stoi(banheiros), stof(valor), proprietario, rua,
                          bairro, cidade);
    return casa;
  } else if (tipo == "apartamento") {
    int andar;
    float taxaCondominio;
    bool elevador, sacada;
    palavra >> andar;
    palavra >> taxaCondominio;
    palavra >> elevador;
    palavra >> sacada;
    Apartamento* apartamento = new Apartamento(
        andar, taxaCondominio, elevador, sacada, 0, stoi(numero), stoi(quartos),
        stoi(banheiros), stof(valor), proprietario, rua, bairro, cidade);
    return apartamento;
  } else if (tipo == "chacara") {
    bool salaoFestas, salaoJogos, campoFutebol, churrasqueira, piscina;
    palavra >> salaoFestas;
    palavra >> salaoJogos;
    palavra >> campoFutebol;
    palavra >> churrasqueira;
    palavra >> piscina;
    Chacara* chacara =
        new Chacara(salaoFestas, salaoJogos, campoFutebol, churrasqueira,
                    piscina, 0, stoi(numero), stoi(quartos), stoi(banheiros),
                    stof(valor), proprietario, rua, bairro, cidade);
    return chacara;
  }
  return nullptr;
}

vector<Imovel*> obterListaDeImoveisPeloValor(vector<Imovel*> listaDeImoveis,
                                             float valor) {
  vector<Imovel*> listaImoveisComValMenorOuIgual;
  for (auto imovel : listaDeImoveis) {
    if (imovel->getValor() <= valor) {
      listaImoveisComValMenorOuIgual.push_back(imovel);
    }
  }
  return listaImoveisComValMenorOuIgual;
}

vector<Imovel*> obterListaDeImoveisPelaQuantidadeQuartos(
    vector<Imovel*> listaDeImoveis, int qtdQuartos) {
  vector<Imovel*> listaImoveisComQtdQuartos;
  for (auto imovel : listaDeImoveis) {
    if (qtdQuartos >= imovel->getQuartos()) {
      listaImoveisComQtdQuartos.push_back(imovel);
    }
  }
  return listaImoveisComQtdQuartos;
}

vector<Imovel*> obterListaDeImoveisPeloTipoDoImovel(
    vector<Imovel*> listaDeImoveis, string tipo) {
  vector<Imovel*> listaImoveisPeloTipo;
  for (auto imovel : listaDeImoveis) {
    Casa* casa = dynamic_cast<Casa*>(imovel);
    if (tipo == "casa" && casa != nullptr)
      listaImoveisPeloTipo.push_back(imovel);

    Apartamento* apartamento = dynamic_cast<Apartamento*>(imovel);
    if (tipo == "apartamento" && apartamento != nullptr)
      listaImoveisPeloTipo.push_back(imovel);

    Chacara* chacara = dynamic_cast<Chacara*>(imovel);
    if (tipo == "chacara" && chacara != nullptr)
      listaImoveisPeloTipo.push_back(imovel);
  }
  return listaImoveisPeloTipo;
}

vector<Imovel*> obterListaDeImoveisPelaCidadeDoImovel(
    vector<Imovel*> listaDeImoveis, string cidade) {
  vector<Imovel*> listaImoveisPelaCidade;
  for (auto imovel : listaDeImoveis) {
    if (cidade == imovel->getCidade()) listaImoveisPelaCidade.push_back(imovel);
  }
  return listaImoveisPelaCidade;
}

vector<Imovel*> obterListaDeImoveisPeloProprietarioDoImovel(
    vector<Imovel*> listaDeImoveis, string proprietario) {
  vector<Imovel*> listaImoveisPelaProprietario;
  for (auto imovel : listaDeImoveis) {
    if (proprietario == imovel->getPropietario())
      listaImoveisPelaProprietario.push_back(imovel);
  }
  return listaImoveisPelaProprietario;
}

int main() {
  cout << fixed << setprecision(2);
  string arquivoImoveis = "dataBaseImoveis.txt", linha;
  ifstream arquivo(arquivoImoveis);
  vector<Imovel*> listaDeImoveis;

  if (!arquivo.is_open()) {
    cout << "Erro ao abrir arquivo de imóveis!" << endl;
    return 1;
  }

  while (getline(arquivo, linha)) {
    Imovel* imovel = criarImovelPelaLinha(linha);
    listaDeImoveis.push_back(imovel);
  }

  // imprimeLista(listaDeImoveis);

  // string proprietario;
  // cout << "Digite o nome do proprietário que você deseja buscar: " << endl;
  // getline(cin, proprietario);

  // if (ehProprietario(listaDeImoveis, proprietario)) {
  //   cout << "É proprietário!" << endl;
  // } else {
  //   cout << "Não é proprietário!" << endl;
  // }

  // float valorBuscado;
  // cout << "Digite pelo valor do imóvel que você deseja buscar: " << endl;
  // cin >> valorBuscado;
  // vector<Imovel*> listaDeImoveisValorBuscado =
  //     obterListaDeImoveisPeloValor(listaDeImoveis, valorBuscado);
  // if (!listaDeImoveisValorBuscado.empty())
  //   imprimeLista(listaDeImoveisValorBuscado);
  // else
  //   cout << "Não existe imovel no intervalo de valor buscado!" << endl;

  // int qtQuartosBuscado;
  // cout << "Digite pela quantidade de quartos do imóvel que você deseja
  // buscar: "
  //      << endl;
  // cin >> qtQuartosBuscado;
  // vector<Imovel*> listaDeImoveisQuartosBuscado =
  //     obterListaDeImoveisPelaQuantidadeQuartos(listaDeImoveis,
  //                                              qtQuartosBuscado);
  // if (!listaDeImoveisQuartosBuscado.empty())
  //   imprimeLista(listaDeImoveisQuartosBuscado);
  // else
  //   cout << "Não existe imovel no intervalo de quartos buscado!" << endl;

  // string tipoImovel;
  // cout << "Digite pelo tipo do imóvel que você deseja buscar: " << endl;
  // getline(cin, tipoImovel);
  // vector<Imovel*> listaDeImoveisTipoDoImovelBuscado =
  //     obterListaDeImoveisPeloTipoDoImovel(listaDeImoveis, tipoImovel);
  // if (!listaDeImoveisTipoDoImovelBuscado.empty())
  //   imprimeLista(listaDeImoveisTipoDoImovelBuscado);
  // else
  //   cout << "Não existe imovel do tipo buscado!" << endl;

  // string cidade;
  // cout
  //     << "Digite pela cidade em que está o imóvel que você deseja buscar
  //     : "
  //     << endl;
  // getline(cin, cidade);
  // vector<Imovel*> listaDeImoveisCidadeDoImovelBuscado =
  //     obterListaDeImoveisPelaCidadeDoImovel(listaDeImoveis, cidade);
  // if (!listaDeImoveisCidadeDoImovelBuscado.empty())
  //   imprimeLista(listaDeImoveisCidadeDoImovelBuscado);
  // else
  //   cout << "Não existe imovel da cidade buscada!" << endl;

  // string proprietarioBuscado;
  // cout << "Digite pelo proprietário que é dono do imóvel que você deseja "
  //         "buscar : "
  //      << endl;
  // getline(cin, proprietarioBuscado);
  // vector<Imovel*> listaDeImoveisProprietarioDoImovelBuscado =
  //     obterListaDeImoveisPeloProprietarioDoImovel(listaDeImoveis,
  //                                                 proprietarioBuscado);
  // if (!listaDeImoveisProprietarioDoImovelBuscado.empty())
  //   imprimeLista(listaDeImoveisProprietarioDoImovelBuscado);
  // else
  //   cout << "Não existe imovel do proprietário buscado!" << endl;

  string escolhaDoUsuario;
  cout << "Digite pela forma que deseja receber os dados dos imóveis: " << endl;
  getline(cin, escolhaDoUsuario);
  imprimeLista(listaDeImoveis, escolhaDoUsuario);
  arquivo.close();
  return 0;
}