#ifndef IMOVEL_H
#define IMOVEL_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;  // coloca o std:: em todos os lugares que precisam

class Imovel {
 private:
  int id, numero, quartos, banheiros;
  float valor;
  string proprietario, rua, bairro, cidade;

 public:
  Imovel(int id, int numero, int quartos, int banheiros, float valor,
         string proprietario, string rua, string bairro, string cidade);
  virtual ~Imovel();
  int getId();
  void setId(int id);
  float getValor();
  void setValor(float val);
  string getPropietario();
  void setProprietario(string nomeProprietario);
  string getRua();
  void setRua(string nomeRua);
  string getBairro();
  void setBairro(string nomeBairro);
  string getCidade();
  void setCidade(string nomeCidade);
  int getNumero();
  void setNumero(int num);
  int getQuartos();
  void setQuartos(int qtdQuartos);
  int getBanheiros();
  void setBanheiros(int banheiros);
  friend ostream& operator<<(ostream& os, Imovel& imovel);
};
#endif  // IMOVEL_H