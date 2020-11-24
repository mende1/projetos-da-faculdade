#include <string.h>

#include <iostream>

#include "playlist.h"

using namespace std;

bool compararDatas(string data1, string data2) {
  // Ano
  if (stoi(data1.substr(6, 4)) > stoi(data2.substr(6, 4))) {
    return true;
  }
  if (stoi(data1.substr(6, 4)) < stoi(data2.substr(6, 4))) {
    return false;
  }

  // Mes
  if (stoi(data1.substr(3, 2)) > stoi(data2.substr(3, 2))) {
    return true;
  }
  if (stoi(data1.substr(3, 2)) < stoi(data2.substr(3, 2))) {
    return false;
  }

  // Dia
  if (stoi(data1.substr(0, 2)) > stoi(data2.substr(0, 2))) {
    return true;
  }
  if (stoi(data1.substr(0, 2)) < stoi(data2.substr(0, 2))) {
    return false;
  }

  // Hora
  if (stoi(data1.substr(11, 2)) > stoi(data2.substr(11, 2))) {
    return true;
  }
  if (stoi(data1.substr(11, 2)) < stoi(data2.substr(11, 2))) {
    return false;
  }

  // Minutos
  if (stoi(data1.substr(14, 2)) > stoi(data2.substr(14, 2))) {
    return true;
  }
  if (stoi(data1.substr(14, 2)) < stoi(data2.substr(14, 2))) {
    return false;
  }
  return false;
}

void sortPlaylistTopN(playlist *playlistGeral, playlist *playlistOrdenada,
                      int n) {
  int i = 0;  // testar numero de loops
  // Primeiro elemento da Playlist Geral
  musica *musicaGeral = playlistGeral->getInicio();
  // Faz uma copia desse elemento
  musica *musicaPlaylist = new musica(
      musicaGeral->getArtista(), musicaGeral->getAlbum(),
      musicaGeral->getGenero(), musicaGeral->getAno(), musicaGeral->getNome(),
      musicaGeral->getDuracao(), musicaGeral->getClassificacao(),
      musicaGeral->getReproducoes(), musicaGeral->getDataAdicao(),
      musicaGeral->getUltimaReproducao());
  // Insere na playlist Ordenada
  playlistOrdenada->InsereElemFim(musicaPlaylist);
  // Vai para a segunda musica da Playlist Geral
  musicaGeral = musicaGeral->getProxima();

  // Varre a Playlist Geral
  while (musicaGeral != NULL) {
    i++;
    // So insere a musica se ou a playlist esta imcompleta ou a musicaGeral possui classificação
    // maior do que a última ou ela possui a mesma classificação e tem maior número de reproduções
    if (playlistOrdenada->getTamanho() != n ||
        musicaGeral->getClassificacao() > playlistOrdenada->getFim()->getClassificacao() ||
        (musicaGeral->getClassificacao() == playlistOrdenada->getFim()->getClassificacao() &&
         musicaGeral->getReproducoes() > playlistOrdenada->getFim()->getReproducoes())) {
      // Faz uma copia da musica Atual
      musica *novaMusica = new musica(
          musicaGeral->getArtista(), musicaGeral->getAlbum(),
          musicaGeral->getGenero(), musicaGeral->getAno(),
          musicaGeral->getNome(), musicaGeral->getDuracao(),
          musicaGeral->getClassificacao(), musicaGeral->getReproducoes(),
          musicaGeral->getDataAdicao(), musicaGeral->getUltimaReproducao());
      // Varre a Playlist Ordenada
      while (musicaPlaylist != NULL) {
        i++;
        // Ver se a classificação é maior ou se ela é igual mas possui maior número de reproduções
        if (musicaGeral->getClassificacao() >
                musicaPlaylist->getClassificacao() ||
            (musicaGeral->getClassificacao() ==
                 musicaPlaylist->getClassificacao() &&
             musicaGeral->getReproducoes() >
                 musicaPlaylist->getReproducoes())) {
          // Insere a musica antes do elemento comparado
          playlistOrdenada->InsereElemento(novaMusica, musicaPlaylist);
          // Encerra o while interno
          break;
        }
        // Vai para a proxima musica da playlist ordenada
        musicaPlaylist = musicaPlaylist->getProxima();

        // Se não existe proxima musica e houver espaco, insere no final
        if (musicaPlaylist == NULL && playlistOrdenada->getTamanho() < n) {
          playlistOrdenada->InsereElemFim(novaMusica);
        }
      }
      // Se a playlist tiver mais elementos que o tamanho máximo, remove o último elemento.
      if (playlistOrdenada->getTamanho() > n) {
        playlistOrdenada->removeElemenFinal(playlistOrdenada->getFim());
      }
    }

    // Volta para a primeira musica da playlist ordenada
    musicaPlaylist = playlistOrdenada->getInicio();
    // Vai para a proxima musica da playlist geral
    musicaGeral = musicaGeral->getProxima();
  }
  cout << "Top n Faixas rodou: " << i << " vezes" << endl;
}

void sortPlaylistNaoEscuto(playlist *playlistGeral, playlist *playlistOrdenada,
                           int n) {
  int i = 0;  // testar numero de loops
  // Primeiro elemento da Playlist Geral
  musica *musicaGeral = playlistGeral->getInicio();
  // Faz uma copia desse elemento
  musica *musicaPlaylist = new musica(
      musicaGeral->getArtista(), musicaGeral->getAlbum(),
      musicaGeral->getGenero(), musicaGeral->getAno(), musicaGeral->getNome(),
      musicaGeral->getDuracao(), musicaGeral->getClassificacao(),
      musicaGeral->getReproducoes(), musicaGeral->getDataAdicao(),
      musicaGeral->getUltimaReproducao());
  // Insere na playlist Ordenada
  playlistOrdenada->InsereElemFim(musicaPlaylist);
  // Vai para a segunda musica da Playlist Geral
  musicaGeral = musicaGeral->getProxima();

  // Varre a Playlist Geral
  while (musicaGeral != NULL) {
    i++;
    // So insere a musica se ela já foi reproduzida e a playlist esta imcompleta ou se a música foi reproduzida e possui classificação
    // maior do que a última ou se ela possui a mesma classificação e foi reproduzida há mais tempo
    if (playlistOrdenada->getTamanho() != n ||
        musicaGeral->getClassificacao() > playlistOrdenada->getFim()->getClassificacao() ||
        (musicaGeral->getClassificacao() == playlistOrdenada->getFim()->getClassificacao() &&
         compararDatas(playlistOrdenada->getFim()->getUltimaReproducao(),
                       musicaGeral->getUltimaReproducao())) &&
            musicaGeral->getUltimaReproducao() != "00/00/0000 00:00") {
      // Faz uma copia da musica Atual
      musica *novaMusica = new musica(
          musicaGeral->getArtista(), musicaGeral->getAlbum(),
          musicaGeral->getGenero(), musicaGeral->getAno(),
          musicaGeral->getNome(), musicaGeral->getDuracao(),
          musicaGeral->getClassificacao(), musicaGeral->getReproducoes(),
          musicaGeral->getDataAdicao(), musicaGeral->getUltimaReproducao());
      // Varre a Playlist Ordenada
      while (musicaPlaylist != NULL) {
        i++;
        // Ver se a música já foi reproduzida e á classificacao é maior, se foi reproduzida e a classificação for igual compara a
        // ultima reproducao
        if ((musicaGeral->getClassificacao() >
                 musicaPlaylist->getClassificacao() ||
             (musicaGeral->getClassificacao() ==
                  musicaPlaylist->getClassificacao() &&
              compararDatas(musicaPlaylist->getUltimaReproducao(),
                            musicaGeral->getUltimaReproducao()))) &&
            musicaGeral->getUltimaReproducao() != "00/00/0000 00:00") {
          // Insere a musica antes do elemento comparado
          playlistOrdenada->InsereElemento(novaMusica, musicaPlaylist);
          // Encerra o while interno
          break;
        }
        // Vai para a proxima musica da playlist ordenada
        musicaPlaylist = musicaPlaylist->getProxima();

        // Se não existe proxima musica e houver espaco, insere no final
        if (musicaPlaylist == NULL && playlistOrdenada->getTamanho() < n &&
            novaMusica->getUltimaReproducao() != "00/00/0000 00:00") {
          playlistOrdenada->InsereElemFim(novaMusica);
        }
      }
      // Se a playlist tiver mais elementos que o tamanho máximo, remove o último elemento.
      if (playlistOrdenada->getTamanho() > n) {
        playlistOrdenada->removeElemenFinal(playlistOrdenada->getFim());
      }
    }
    // Volta para a primeira musica da playlist ordenada
    musicaPlaylist = playlistOrdenada->getInicio();
    // Vai para a proxima musica da playlist geral
    musicaGeral = musicaGeral->getProxima();
  }
  cout << "Não escuto a muito tempo: " << i << " vezes" << endl;
}

void sortRecentes(playlist *playlistGeral,
                                playlist *playlistOrdenada, int n,
                                bool tipoOrdenacao) {
  int i = 0;  // testar numero de loops
  // Primeiro elemento da Playlist Geral
  musica *musicaGeral = playlistGeral->getInicio();
  // Faz uma copia desse elemento
  musica *musicaPlaylist = new musica(
      musicaGeral->getArtista(), musicaGeral->getAlbum(),
      musicaGeral->getGenero(), musicaGeral->getAno(), musicaGeral->getNome(),
      musicaGeral->getDuracao(), musicaGeral->getClassificacao(),
      musicaGeral->getReproducoes(), musicaGeral->getDataAdicao(),
      musicaGeral->getUltimaReproducao());
  // Insere na playlist Ordenada
  playlistOrdenada->InsereElemFim(musicaPlaylist);
  // Vai para a segunda musica da Playlist Geral
  musicaGeral = musicaGeral->getProxima();

  // Varre a Playlist Geral
  while (musicaGeral != NULL) {
    i++;
    // So insere a musica se a playlist esta imcompleta ou a musicaGeral é
    // maior que o último elemento da nova playlist.
    if ((playlistOrdenada->getTamanho() != n) ||
        ((tipoOrdenacao == 1 &&
          compararDatas(musicaGeral->getDataAdicao(),
                        playlistOrdenada->getFim()->getDataAdicao())) ||
         (tipoOrdenacao == 0 &&
          compararDatas(musicaGeral->getUltimaReproducao(),
                        playlistOrdenada->getFim()->getUltimaReproducao())))) {
      // Faz uma copia da musica Atual
      musica *novaMusica = new musica(
          musicaGeral->getArtista(), musicaGeral->getAlbum(),
          musicaGeral->getGenero(), musicaGeral->getAno(),
          musicaGeral->getNome(), musicaGeral->getDuracao(),
          musicaGeral->getClassificacao(), musicaGeral->getReproducoes(),
          musicaGeral->getDataAdicao(), musicaGeral->getUltimaReproducao());
      // Varre a Playlist Ordenada
      while (musicaPlaylist != NULL) {
        i++;
        // Vê se a ultima reproducao ou a data de adição (dependendo da ordenação) é maior
        if ((tipoOrdenacao == 1 &&
             compararDatas(musicaGeral->getDataAdicao(),
                           musicaPlaylist->getDataAdicao())) ||
            (tipoOrdenacao == 0 &&
             compararDatas(musicaGeral->getUltimaReproducao(),
                           musicaPlaylist->getUltimaReproducao()))) {
          // Insere a musica antes do elemento comparado
          playlistOrdenada->InsereElemento(novaMusica, musicaPlaylist);
          // Encerra o while interno
          break;
        }
        // Vai para a proxima musica da playlist ordenada
        musicaPlaylist = musicaPlaylist->getProxima();

        // Se não existe proxima musica e houver espaco, insere no final.
        if (musicaPlaylist == NULL && playlistOrdenada->getTamanho() < n) {
          playlistOrdenada->InsereElemFim(novaMusica);
        }
      }
      // Se a playlist tiver mais elementos que o tamanho máximo, remove o último elemento.
      if (playlistOrdenada->getTamanho() > n) {
        playlistOrdenada->removeElemenFinal(playlistOrdenada->getFim());
      }
    }

    // Volta para a primeira musica da playlist ordenada
    musicaPlaylist = playlistOrdenada->getInicio();
    // Vai para a proxima musica da playlist geral
    musicaGeral = musicaGeral->getProxima();
  }
  cout <<  ((tipoOrdenacao == 1) ? "Acabei de Baixar rodou: " : "Acabei de Escutar rodou: ")  << i << " vezes" << endl;
}

