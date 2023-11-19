#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "imovel.h"

using namespace std;

namespace FuncoesAuxiliares {
void imprimeImovel(Imovel* imovel, ostream* ostream);
void imprimeListaDeImoveis(vector<Imovel*> listaDeImoveis, ostream* ostream);
void imprimeListaOuSalvaEmArquivo(vector<Imovel*> listaDeImoveis,
                                  string escolhaUsuario);
bool ehProprietario(vector<Imovel*> listaImoveis, string proprietario);
Imovel* criarImovelPelaLinha(string linha, int id);
vector<Imovel*> obterListaDeImoveisPeloValor(vector<Imovel*> listaDeImoveis,
                                             float valor);
vector<Imovel*> obterListaDeImoveisPelaQuantidadeQuartos(
    vector<Imovel*> listaDeImoveis, int qtdQuartos);
vector<Imovel*> obterListaDeImoveisPeloTipoDoImovel(
    vector<Imovel*> listaDeImoveis, string tipo);
vector<Imovel*> obterListaDeImoveisPelaCidadeDoImovel(
    vector<Imovel*> listaDeImoveis, string cidade);
vector<Imovel*> obterListaDeImoveisPeloProprietarioDoImovel(
    vector<Imovel*> listaDeImoveis, string proprietario);
map<string, vector<Imovel*>> tabelaHash(vector<Imovel*> listaDeImoveis);
void limpaBuffer();
};  // namespace FuncoesAuxiliares

#endif  // FUNCOES_AUXILIARES_H