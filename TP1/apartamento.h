#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include <iostream>

#include "imovel.h"
using namespace std;

class Apartamento : public Imovel {
 private:
  int andar;
  float taxaCondominio;
  bool elevador, sacada;

 public:
  Apartamento(int andar, float taxaCondominio, bool elevador, bool sacada,
              int id, int numero, int quartos, int banheiros, float valor,
              string proprietario, string rua, string bairro, string cidade);
  friend ostream& operator<<(ostream& os, Apartamento& apartamento);
  int getAndar();
  void setAndar(int andar);
  float getTaxaCondominio();
  void setTaxaCondominio(float taxa);
  bool getElevador();
  void setElevador(bool elevador);
};

#endif  // APARTAMENTO_H