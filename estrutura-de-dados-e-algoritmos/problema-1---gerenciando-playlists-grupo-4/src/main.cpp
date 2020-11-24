#include <iostream>

#include "openCsv.h"
#include "playlist.h"
#include "playlistOrdenacao.h"

using namespace std;

playlist *geral = new playlist();

int main(int argc, char *argv[]) {
  string usuario = (argc > 1) ? (argv[1]) : "MusicDataBase-G4";
  cout << "Abrindo arquivo " << usuario + ".csv" << endl;

  if (readFile(geral, usuario) == false) {
    std::cout << "Erro ao abrir arquivo. Verifique o nome de usuário" << '\n';
    return 0;
  };

  int a = (argc > 2) ? atoi(argv[2]) : 10;
  playlist *topNfaixas = new playlist();
  playlist *acabeiDeBaixar = new playlist();
  playlist *acabeiDeEscutar = new playlist();
  playlist *naoEscutoAmuitoTempo = new playlist();

  sortPlaylistTopN(geral, topNfaixas, a);
  sortRecentes(geral, acabeiDeBaixar, a, 1);
  sortRecentes(geral, acabeiDeEscutar, a, 0);
  sortPlaylistNaoEscuto(geral, naoEscutoAmuitoTempo, a);

  writeFile(topNfaixas, usuario + "-Top-N-Faixas.csv");
  writeFile(acabeiDeBaixar, usuario + "-Acabei-de-Baixar.csv");
  writeFile(acabeiDeEscutar, usuario + "-Acabei-de-Escutar.csv");
  writeFile(naoEscutoAmuitoTempo, usuario + "-Nao-escuto-a-muito-tempo.csv");
}
