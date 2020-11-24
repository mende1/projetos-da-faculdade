#include <iostream>
#include "musica.h"

using namespace std;

musica::musica(string artista, string album, string genero, int ano,
               string nome, string duracao, int classificacao, int reproducoes,
               string dataAdicao, string ultimaReproducao) {
				   
  this->artista = artista;
  this->album = album;
  this->genero = genero;
  this->ano = ano;
  this->nome = nome;
  this->duracao = duracao;
  this->classificacao = classificacao;
  this->reproducoes = reproducoes;
  this->dataAdicao = dataAdicao;
  this->ultimaReproducao = ultimaReproducao;
  proxima = NULL;
  anterior = NULL;
}

musica::~musica() {}

string musica::getArtista() { return artista; }
string musica::getAlbum() { return album; }
string musica::getGenero() { return genero; }
string musica::getNome() { return nome; }
string musica::getDuracao() { return duracao; }
string musica::getDataAdicao() { return dataAdicao; }
string musica::getUltimaReproducao() { return ultimaReproducao; }

int musica::getAno() { return ano; }
int musica::getClassificacao() { return classificacao; }
int musica::getReproducoes() { return reproducoes; }

musica* musica::getProxima() { return proxima; }
musica* musica::getAnterior() { return anterior; }

void musica::setArtista(string a) { artista = a; }
void musica::setAlbum(string a) { album = a; }
void musica::setGenero(string g) { genero = g; }
void musica::setNome(string n) { nome = n; }
void musica::setDuracao(string d) { duracao = d; }
void musica::setDataAdicao(string d) { dataAdicao = d; }
void musica::setUltimaReproducao(string u) { ultimaReproducao = u; }

void musica::setAno(int a) { ano = a; }
void musica::setClassificacao(int c) { classificacao = c; }
void musica::setReproducoes(int r) { reproducoes = r; }

void musica::setProxima(musica* p) { proxima = p; }
void musica::setAnterior(musica* p) { anterior = p; }