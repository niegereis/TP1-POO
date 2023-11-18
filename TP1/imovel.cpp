#include "imovel.h"

Imovel::Imovel(int id, int numero, int quartos, int banheiros, float valor,
               string proprietario, string rua, string bairro, string cidade) {
  this->id = id;
  this->numero = numero;
  this->quartos = quartos;
  this->banheiros = banheiros;
  this->valor = valor;
  this->proprietario = proprietario;
  this->rua = rua;
  this->bairro = bairro;
  this->cidade = cidade;
}

Imovel::~Imovel() {}

int Imovel::getId() { return this->id; }

void Imovel::setId(int id) { this->id = id; }

float Imovel::getValor() { return this->valor; }

void Imovel::setValor(float val) { this->valor = val; }

string Imovel::getPropietario() { return this->proprietario; }

void Imovel::setProprietario(string nomeProprietario) {
  this->proprietario = proprietario;
}

string Imovel::getRua() { return this->rua; }

void Imovel::setRua(string nomeRua) { this->rua = nomeRua; }

string Imovel::getBairro() { return this->bairro; }

void Imovel::setBairro(string nomeBairro) { this->bairro = nomeBairro; }

string Imovel::getCidade() { return this->cidade; }

void Imovel::setCidade(string nomeCidade) { this->cidade = nomeCidade; }

int Imovel::getNumero() { return this->numero; }

void Imovel::setNumero(int num) { this->numero = num; }

int Imovel::getQuartos() { return this->quartos; }

void Imovel::setQuartos(int qtdQuartos) { this->quartos = qtdQuartos; }

int Imovel::getBanheiros() { return this->banheiros; }

void Imovel::setBanheiros(int banheiros) { this->banheiros = banheiros; }