#ifndef _CLASSE_DA_MUSICA_
#define _CLASSE_DA_MUSICA_

#include <iostream>

using namespace std;

class musica {
 private:
  string artista, album, genero, nome, duracao, dataAdicao, ultimaReproducao;
  int ano, classificacao, reproducoes;
  musica *proxima;
  musica *anterior;

 public:
  musica(string artista, string album, string genero, int ano, string nome,
         string duracao, int classificacao, int reproducoes, string dataAdicao,
         string ultimaReproducao);

  ~musica();

  string getArtista();
  string getAlbum();
  string getGenero();
  string getNome();
  string getDuracao();
  string getDataAdicao();
  string getUltimaReproducao();

  int getAno();
  int getClassificacao();
  int getReproducoes();

  musica *getProxima();
  musica *getAnterior();

  void setArtista(string a);
  void setAlbum(string a);
  void setGenero(string g);
  void setNome(string n);
  void setDuracao(string d);
  void setDataAdicao(string d);
  void setUltimaReproducao(string u);

  void setAno(int a);
  void setClassificacao(int c);
  void setReproducoes(int r);

  void setProxima(musica *p);
  void setAnterior(musica *p);
};

#endif //_CLASSE_DA_MUSICA_