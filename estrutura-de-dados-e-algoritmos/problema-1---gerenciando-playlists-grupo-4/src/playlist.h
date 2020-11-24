#ifndef _CLASSE_DA_PLAYLIST_
#define _CLASSE_DA_PLAYLIST_

#include <iostream>
#include "musica.h"

using namespace std;

class playlist {
 private:
  musica* inicio;
  musica* fim;
  int tamanho;

 public:
  playlist();
  ~playlist();

  musica* getInicio();

  int getTamanho();

  void InsereElemFim(musica* musicaAdicionada);
  void InsereElemento(musica *musicaAdicionada, musica *comparada);
  void removeElemenFinal(musica *musicaRemovida);

  musica* getFim();
};

#endif //_CLASSE_DA_PLAYLIST_