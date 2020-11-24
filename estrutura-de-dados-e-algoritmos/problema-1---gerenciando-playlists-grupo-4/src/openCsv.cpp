#include "openCsv.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "playlistOrdenacao.h"


using namespace std;

void writeFile(playlist *playlistParaSalvar, string nomeDaPlanilha) {
  fstream fout;

  fout.open("database/" + nomeDaPlanilha, ios::out | std::ofstream::trunc);

  string values[10];
  string artista;
  string album;
  string Genero;
  int Ano;
  string Nome;
  string Duracao;
  int Classificacao;
  int Reproducoes;
  string DataAdicao;
  string UltimaReproducao;

  musica *musicaAtual = playlistParaSalvar->getInicio();
  fout << "Artista,Album,Genero,Ano,Nome,Duracao,Classificação,Reproducoes,"
          "DataAdicao,UltimaReproducao\n";
  while (musicaAtual != NULL) {
    artista = musicaAtual->getArtista();
    album = musicaAtual->getAlbum();
    Genero = musicaAtual->getGenero();
    Ano = musicaAtual->getAno();
    Nome = musicaAtual->getNome();
    Duracao = musicaAtual->getDuracao();
    Classificacao = musicaAtual->getClassificacao();
    Reproducoes = musicaAtual->getReproducoes();
    DataAdicao = musicaAtual->getDataAdicao();
    UltimaReproducao = musicaAtual->getUltimaReproducao();

    fout << artista << "," << album << "," << Genero << "," << Ano << ","
         << Nome << "," << Duracao << "," << Classificacao << "," << Reproducoes
         << "," << ((DataAdicao == "00/00/0000 00:00") ? "" : DataAdicao) << ","
         << ((UltimaReproducao == "00/00/0000 00:00") ? "" : UltimaReproducao)
         << "\n";
    musicaAtual = musicaAtual->getProxima();
  }
}

bool readFile(playlist *geral, string usuario) {
  ifstream ip("database/" + usuario + ".csv");

  if (!ip.is_open()) {
    return false;
  }

  string keys[10] = {
      "artista",    "album",           "Genero",        "Ano",
      "Nome",       "Duracao",         "Classificacao", "Reproducoes",
      "DataAdicao", "UltimaReproducao"};
  string values[10];
  string artista;
  string album;
  string Genero;
  int Ano;
  string Nome;
  string Duracao;
  int Classificacao;
  int Reproducoes;
  string DataAdicao;
  string UltimaReproducao;
  std::vector<musica> arrayDeMusicas;

  while (ip.good()) {
    for (int i = 0; i < 10; i++) values[i] = "";

    string line;
    getline(ip, line);

    int i = 0;
    bool aspas = false;
    string palavra;

    for (int letter = 0; letter < line.size(); letter++) {
      if (line[letter] == '"') {
        aspas = !aspas;
      } else if (aspas == true) {
        if (line[letter] != '"')
          palavra += line[letter];
        else {
          values[i] = palavra;
          i += 1;
          palavra = "";
          aspas = !aspas;
        }
      }

      else {
        if (i == 9) {
          if (letter == (line.size() - 1)) {
            values[i] = palavra;
            if (values[9].size() == 15) values[9].insert(11, "0");
            i++;
            palavra = "";
          } else
            palavra += line[letter];
        } else {
          if (line[letter] == ',') {
            values[i] = palavra;
            i += 1;
            palavra = "";
          } else
            palavra += line[letter];
        }
      }
    }
    artista = values[0];
    album = values[1];
    Genero = values[2];
    Ano = atoi(values[3].c_str());
    Nome = values[4];
    Duracao = values[5];
    Classificacao = atoi(values[6].c_str());
    Reproducoes = atoi(values[7].c_str());
    DataAdicao = (values[8] == "" ? "00/00/0000 00:00" : values[8]);
    UltimaReproducao = (values[9] == "" ? "00/00/0000 00:00" : values[9]);
    musica *novaMusica =
        new musica(artista, album, Genero, Ano, Nome, Duracao, Classificacao,
                   Reproducoes, DataAdicao, UltimaReproducao);

    if (UltimaReproducao != "UltimaReproducao")
      geral->InsereElemFim(novaMusica);
  }
  std::cout << endl << endl;
  ip.close();
  return true;
}

