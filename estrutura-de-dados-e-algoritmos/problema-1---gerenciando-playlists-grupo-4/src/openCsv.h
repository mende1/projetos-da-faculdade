#ifndef _ENTRADA_E_SAIDA_CSV_
#define _ENTRADA_E_SAIDA_CSV_

#include <iostream>
#include "playlist.h"

using namespace std;

void writeFile(playlist* playlistParaSalvar, string nomeDaPlanilha);
bool readFile(playlist *geral, string usuario);

#endif //_ENTRADA_E_SAIDA_CSV_