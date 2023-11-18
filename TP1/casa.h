#ifndef CASA_H
#define CASA_H
#include <iostream>

#include "imovel.h"
using namespace std;

class Casa : public Imovel {
 private:
  int andares;
  bool salaJantar;

 public:
  Casa(int andares, bool salaJantar, int id, int numero, int quartos,
       int banheiros, float valor, string proprietario, string rua,
       string bairro, string cidade);
  friend ostream& operator<<(ostream& os, Casa& casa);
  int getAndares();
  void setAndares(int andares);
  int getSalaJantar();
  void setSalaJantar(bool salaJantar);
};

#endif  // CASA_H