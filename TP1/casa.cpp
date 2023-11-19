#include "casa.h"

Casa::Casa(int andares, bool salaJantar, int id, int numero, int quartos,
           int banheiros, float valor, string proprietario, string rua,
           string bairro, string cidade)
    : Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro,
             cidade) {
  this->andares = andares;
  this->salaJantar = salaJantar;
}

void Casa::func() { cout << "asd" << endl; }

ostream& operator<<(ostream& os, Casa& casa) {
  os << "- - - - -" << endl;
  os << "\tProprietário " << casa.getPropietario() << endl;
  os << "\tPreço " << casa.getValor() << endl;
  os << "\tNúmero de quartos: " << casa.getNumero() << endl;
  os << "\tRua: " << casa.getRua() << endl;
  os << "\tBairro: " << casa.getBairro() << endl;
  os << "\tCidade: " << casa.getCidade() << endl;

  os << "\tCaracterística Específica: ";
  if (casa.getAndares())
    os << "Casa tem " << casa.getAndares() << " andares!";
  else
    os << "Casa não tem nenhum andar...";
  os << endl;

  os << "- - - - -" << endl;
  return os;
}

int Casa::getAndares() { return this->andares; }

void Casa::setAndares(int andares) { this->andares = andares; }

int Casa::getSalaJantar() { return this->salaJantar; }

void Casa::setSalaJantar(bool salaJantar) { this->salaJantar = salaJantar; }