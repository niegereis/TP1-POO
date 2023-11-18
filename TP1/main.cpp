#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "imovel.h"

using namespace std;

int main() {
  string arquivoImoveis = "dataBaseImoveis.txt", linha;
  ifstream arquivo(arquivoImoveis);
  vector<Imovel> listaDeImoveis;

  if (!arquivo.is_open()) {
    cout << "Erro ao abrir arquivo de imóveis!" << endl;
    return 1;
  }

  while (getline(arquivo, linha)) {
    istringstream palavra(linha);

    int numero, quartos, banheiros;
    float valor;
    string tipo, proprietario, rua, bairro, cidade;

    getline(palavra, tipo, ';');
    palavra >> valor;
    getline(palavra, proprietario, ';');
    cout << tipo << " " << valor << " " << proprietario << endl;
    // cout << proprietario << endl;
    getline(palavra, rua, ';');
    getline(palavra, bairro, ';');
    getline(palavra, cidade, ';');
    // palavra >> numero;
    // palavra >> quartos;
    // cout << quartos << endl;
    // palavra >> banheiros;

    // if (tipo == "casa") {
    //   int andares;
    //   bool salaJantar;
    //   palavra >> andares;
    //   palavra >> salaJantar;
    //   Casa* casa = new Casa(andares, salaJantar, 0, numero, quartos,
    //   banheiros,
    //                         valor, proprietario, rua, bairro, cidade);
    //   cout << *casa << endl;
    // } else if (tipo == "apartamento") {
    //   int andar;
    //   float taxaCondominio;
    //   bool elevador, sacada;
    //   palavra >> andar;
    //   palavra >> taxaCondominio;
    //   palavra >> elevador;
    //   palavra >> sacada;
    //   Apartamento* apartamento = new Apartamento(
    //       andar, taxaCondominio, elevador, sacada, 0, numero, quartos,
    //       banheiros, valor, proprietario, rua, bairro, cidade);
    //   cout << *apartamento << endl;
    // } else if (tipo == "chacara") {
    //   bool salaoFestas, salaoJogos, campoFutebol, churrasqueira, piscina;
    //   palavra >> salaoFestas;
    //   palavra >> salaoJogos;
    //   palavra >> campoFutebol;
    //   palavra >> churrasqueira;
    //   palavra >> piscina;
    //   Chacara* chacara = new Chacara(
    //       salaoFestas, salaoJogos, campoFutebol, churrasqueira, piscina, 0,
    //       numero, quartos, banheiros, valor, proprietario, rua, bairro,
    //       cidade);
    //   cout << *chacara << endl;
    // }
  }

  arquivo.close();
  return 0;
}