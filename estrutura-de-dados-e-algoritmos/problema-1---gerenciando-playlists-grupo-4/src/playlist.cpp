#include <iostream>
#include "playlist.h"

using namespace std;

playlist::playlist() {
  inicio = NULL;
  fim = NULL;
  tamanho = 0;
}

playlist::~playlist() {
  musica* aux = inicio;

  while (inicio != NULL) {
    aux = (*inicio).getProxima();
    delete inicio;
    inicio = aux;
  }
}

musica* playlist::getInicio(){ return inicio; }

void playlist::InsereElemFim(musica *musicaAdionada) {
  if (inicio == NULL) {  // lista vazia
    inicio = musicaAdionada;
    fim = musicaAdionada;
  } else {
    // Faz a ultima musica apontar para a musica inserida
    fim->setProxima(musicaAdionada);
    musicaAdionada->setAnterior(fim);
    fim = musicaAdionada;
  }
  tamanho++;
}

void playlist::InsereElemento(musica *musicaAdicionada, musica *comparada) {
  musica *aux;

  // Insercao no meio
  if (comparada->getAnterior() != NULL) {
    aux = comparada->getAnterior();
    comparada->setAnterior(musicaAdicionada);
    musicaAdicionada->setProxima(comparada);
    musicaAdicionada->setAnterior(aux);
    aux->setProxima(musicaAdicionada);
  } else {
    // Insercao no Inicio
    inicio = musicaAdicionada;
    comparada->setAnterior(musicaAdicionada);
    musicaAdicionada->setAnterior(NULL);
    musicaAdicionada->setProxima(comparada);
  }
  tamanho++;
}

void playlist::removeElemenFinal(musica *musicaRemovida) {
    if ((musicaRemovida->getAnterior() == NULL) &&
        (musicaRemovida->getProxima() == NULL)) {
      inicio = NULL;
      fim = NULL;
    } else {
      if (musicaRemovida->getAnterior() == NULL) {
        inicio = musicaRemovida->getProxima();
        musicaRemovida->getProxima()->setAnterior(NULL);
      }
      if (musicaRemovida->getProxima() == NULL) {
        fim = musicaRemovida->getAnterior();
        musicaRemovida->getAnterior()->setProxima(NULL);
      }
    }

    if ((musicaRemovida->getAnterior() != NULL) &&
        (musicaRemovida->getProxima() != NULL)) {
      musicaRemovida->getAnterior()->setProxima(musicaRemovida->getProxima());
      musicaRemovida->getProxima()->setAnterior(musicaRemovida->getAnterior());
    }
    delete musicaRemovida;
    tamanho--;
}

int playlist::getTamanho(){
  return tamanho;
}

musica* playlist::getFim() { return fim; }