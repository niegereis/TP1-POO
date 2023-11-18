#include "chacara.h"

Chacara::Chacara(bool salaoFesta, bool salaoJogos, bool campoFutebol,
                 bool churrasqueira, bool piscina, int id, int numero,
                 int quartos, int banheiros, float valor, string proprietario,
                 string rua, string bairro, string cidade)
    : Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro,
             cidade) {
  this->salaoFesta = salaoFesta;
  this->salaoJogos = salaoJogos;
  this->campoFutebol = campoFutebol;
  this->churrasqueira = churrasqueira;
  this->piscina = piscina;
}

ostream& operator<<(ostream& os, Chacara& chacara) {
  os << "- - - - -" << endl;
  os << "\tProprietário " << chacara.getPropietario() << endl;
  os << "\tPreço " << chacara.getValor() << endl;
  os << "\tNúmero de quartos: " << chacara.getNumero() << endl;
  os << "\tRua: " << chacara.getRua() << endl;
  os << "\tBairro: " << chacara.getBairro() << endl;
  os << "\tCidade: " << chacara.getCidade() << endl;

  os << "\tCaracterística Específica: ";
  if (chacara.getPiscina())
    os << "Chácara tem piscina!";
  else
    os << "Chácara não tem piscina...";
  os << endl;

  os << "- - - - -" << endl;
  return os;
}

bool Chacara::getSalaoFesta() { return this->salaoFesta; }

void Chacara::setSalaoFesta(bool salaoFesta) { this->salaoFesta = salaoFesta; }

bool Chacara::getSalaoJogos() { return this->salaoJogos; }

void Chacara::setSalaoJogos(bool salaoJogos) { this->salaoJogos = salaoJogos; }

bool Chacara::getCampoFutebol() { return this->campoFutebol; }

void Chacara::setCampoFutebol(bool campoFutebol) {
  this->campoFutebol = campoFutebol;
}

bool Chacara::getChurrasqueira() { return this->churrasqueira; }

void Chacara::setChurrasqueira(bool churraqueira) {
  this->churrasqueira = churraqueira;
}

bool Chacara::getPiscina() { return this->piscina; }

void Chacara::setPiscina(bool piscina) { this->piscina = piscina; }
