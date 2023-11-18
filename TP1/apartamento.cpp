#include "apartamento.h"

Apartamento ::Apartamento(int andar, float taxaCondominio, bool elevador,
                          bool sacada, int id, int numero, int quartos,
                          int banheiros, float valor, string proprietario,
                          string rua, string bairro, string cidade)
    : Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro,
             cidade) {
  this->andar = andar;
  this->taxaCondominio = taxaCondominio;
  this->elevador = elevador;
  this->sacada = sacada;
}

ostream& operator<<(ostream& os, Apartamento& ap) {
  os << "- - - - -" << endl;
  os << "\tProprietário " << ap.getPropietario() << endl;
  os << "\tPreço " << ap.getValor() << endl;
  os << "\tNúmero de quartos: " << ap.getNumero() << endl;
  os << "\tRua: " << ap.getRua() << endl;
  os << "\tBairro: " << ap.getBairro() << endl;
  os << "\tCidade: " << ap.getCidade() << endl;

  os << "\tCaracterística Específica: ";
  if (ap.getElevador())
    os << "Apartamento tem elevador!";
  else
    os << "Apartamento não tem elevador...";
  os << endl;

  os << "- - - - -" << endl;
  return os;
}

int Apartamento::getAndar() { return this->andar; }

void Apartamento::setAndar(int andar) { this->andar = andar; }

float Apartamento::getTaxaCondominio() { return this->taxaCondominio; }

void Apartamento::setTaxaCondominio(float taxa) { this->taxaCondominio = taxa; }

bool Apartamento::getElevador() { return this->elevador; }

void Apartamento::setElevador(bool elevador) { this->elevador = elevador; }