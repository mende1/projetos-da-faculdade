#ifndef _ALGORITMOS_DE_ORDENACAO_
#define _ALGORITMOS_DE_ORDENACAO_

#include <iostream>

#include "playlist.h"

using namespace std;

bool dataMaior(string data1, string data2);

void sortPlaylistTopN(playlist *playlistGeral, playlist *playlistOrdenada,
                      int n);
void sortPlaylistNaoEscuto(playlist *playlistGeral, playlist *playlistOrdenada,
                           int n);
void sortRecentes(playlist *playlistDesordenada,
                                playlist *playlistOrdenada, int n, bool tipoOrdenacao);
void sortPlaylistAcabeiDeEscutar(playlist *playlistDesordenada,
                                 playlist *playlistOrdenada, int n);

#endif  //_ALGORITMOS_DE_ORDENACAO_