#ifndef CHACARA_H
#define CHACARA_H
#include <iostream>

#include "imovel.h"
using namespace std;

class Chacara : public Imovel {
 private:
  bool salaoFesta, salaoJogos, campoFutebol, churrasqueira, piscina;

 public:
  Chacara(bool salaoFesta, bool salaoJogos, bool campoFutebol,
          bool churrasqueira, bool piscina, int id, int numero, int quartos,
          int banheiros, float valor, string proprietario, string rua,
          string bairro, string cidade);
  friend ostream& operator<<(ostream& os, Chacara& chacara);
  bool getSalaoFesta();
  void setSalaoFesta(bool);
  bool getSalaoJogos();
  void setSalaoJogos(bool);
  bool getCampoFutebol();
  void setCampoFutebol(bool);
  bool getChurrasqueira();
  void setChurrasqueira(bool);
  bool getPiscina();
  void setPiscina(bool);
};
#endif  // CHACARA_H