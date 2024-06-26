#include "funcoesAuxiliares.h"

void FuncoesAuxiliares::imprimeImovel(Imovel* imovel, ostream* ostream) {
  Casa* casa = dynamic_cast<Casa*>(imovel);
  if (casa != nullptr) *ostream << *casa << endl;

  Apartamento* apartamento = dynamic_cast<Apartamento*>(imovel);
  if (apartamento != nullptr) *ostream << *apartamento << endl;

  Chacara* chacara = dynamic_cast<Chacara*>(imovel);
  if (chacara != nullptr) *ostream << *chacara << endl;
}

void FuncoesAuxiliares::imprimeListaDeImoveis(vector<Imovel*> listaDeImoveis,
                                              ostream* ostream) {
  for (Imovel* imovel : listaDeImoveis) {
    imprimeImovel(imovel, ostream);
  }
}

void FuncoesAuxiliares::imprimeListaDeImoveisIt(
    vector<vector<Imovel*>::iterator> listaDeImoveis, ostream* ostream) {
  for (auto it : listaDeImoveis) {
    imprimeImovel(*it, ostream);
  }
}

void FuncoesAuxiliares::imprimeListaOuSalvaEmArquivo(
    vector<Imovel*> listaDeImoveis, string escolhaUsuario) {
  if (escolhaUsuario == "imprime") {
    imprimeListaDeImoveis(listaDeImoveis, &cout);
  } else if (escolhaUsuario == "arquivo") {
    string nomeArquivoSaida = "saida.txt";
    ofstream arquivoDeSaida(nomeArquivoSaida);
    if (arquivoDeSaida.is_open()) {
      imprimeListaDeImoveis(listaDeImoveis, &arquivoDeSaida);
      arquivoDeSaida.close();
      cout << "Os dados foram salvos no arquivo " << nomeArquivoSaida << endl;
    } else {
      cerr << "Erro ao abrir o arquivo " << nomeArquivoSaida << endl;
    }
  }
}

bool FuncoesAuxiliares::ehProprietario(vector<Imovel*> listaImoveis,
                                       string proprietario) {
  for (Imovel* imovel : listaImoveis) {
    if (imovel->getPropietario() == proprietario) return true;
  }
  return false;
}

Imovel* FuncoesAuxiliares::criarImovelPelaLinha(string linha, int id) {
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
    Casa* casa = new Casa(andares, salaJantar, id, stoi(numero), stoi(quartos),
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
    Apartamento* apartamento =
        new Apartamento(andar, taxaCondominio, elevador, sacada, id,
                        stoi(numero), stoi(quartos), stoi(banheiros),
                        stof(valor), proprietario, rua, bairro, cidade);
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
                    piscina, id, stoi(numero), stoi(quartos), stoi(banheiros),
                    stof(valor), proprietario, rua, bairro, cidade);
    return chacara;
  }
  return nullptr;
}

void FuncoesAuxiliares::limpaBuffer() {
  while ((getchar()) != '\n')
    ;
}

vector<Imovel*> FuncoesAuxiliares::obterListaDeImoveisPeloValor(
    vector<Imovel*> listaDeImoveis, float valor) {
  vector<Imovel*> listaImoveisComValMenorOuIgual;
  for (auto imovel : listaDeImoveis) {
    if (imovel->getValor() <= valor) {
      listaImoveisComValMenorOuIgual.push_back(imovel);
    }
  }
  return listaImoveisComValMenorOuIgual;
}

vector<Imovel*> FuncoesAuxiliares::obterListaDeImoveisPelaQuantidadeQuartos(
    vector<Imovel*> listaDeImoveis, int qtdQuartos) {
  vector<Imovel*> listaImoveisComQtdQuartos;
  for (auto imovel : listaDeImoveis) {
    if (qtdQuartos >= imovel->getQuartos()) {
      listaImoveisComQtdQuartos.push_back(imovel);
    }
  }
  return listaImoveisComQtdQuartos;
}

vector<Imovel*> FuncoesAuxiliares::obterListaDeImoveisPeloTipoDoImovel(
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
  sort(listaImoveisPeloTipo.begin(), listaImoveisPeloTipo.end(),
       [](Imovel* im1, Imovel* im2) {
         return im1->getValor() < im2->getValor();
       });
  return listaImoveisPeloTipo;
}

vector<Imovel*> FuncoesAuxiliares::obterListaDeImoveisPelaCidadeDoImovel(
    vector<Imovel*> listaDeImoveis, string cidade) {
  vector<Imovel*> listaImoveisPelaCidade;
  for (auto imovel : listaDeImoveis) {
    if (cidade == imovel->getCidade()) listaImoveisPelaCidade.push_back(imovel);
  }
  sort(listaImoveisPelaCidade.begin(), listaImoveisPelaCidade.end(),
       [](Imovel* im1, Imovel* im2) {
         return im1->getValor() > im2->getValor();
       });
  return listaImoveisPelaCidade;
}

vector<vector<Imovel*>::iterator>
FuncoesAuxiliares::obterListaDeImoveisPeloProprietarioDoImovel(
    vector<Imovel*> listaDeImoveis, string proprietario) {
  vector<vector<Imovel*>::iterator> listaImoveisPelaProprietario;
  for (auto it = listaDeImoveis.begin(); it != listaDeImoveis.end(); ++it) {
    if (proprietario == (*it)->getPropietario())
      listaImoveisPelaProprietario.push_back(it);
  }
  return listaImoveisPelaProprietario;
}