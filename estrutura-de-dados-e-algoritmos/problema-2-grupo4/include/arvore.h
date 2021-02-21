#include <iostream>
#include <vector>

using namespace std;

#include <vector>

#include "no.h"
#include "sCoordQuad.h"
#include "cOpenGLWindow.h"

class arvore
{
private:
  no *raiz;

public:
  arvore(no *raiz);
  ~arvore();

  no *getRaiz();
  void setRaiz(no *raiz);

  void criaArvore(no *root, int funcao);

  void desenhaArvore(no *noAtual, bool quadric, int funcao, cOpenGLWindow win);

  void buscaRayTracing(no *noAtual, float a, float b, int funcao, int ray, bool &achou, cOpenGLWindow win);

  void percorreArvoreDeletando(no *noAtual);

  //Funções Auxiliares
  void calculaFuncao(no *p, float pontos[], int funcao);

  bool estaDentro(float pontos[], no *p);

  void desenhaPonto(float pontos[], no *p, cOpenGLWindow win);

  vector<float> getReta(float x0, float y0, float x1, float y1);

  vector<float> getIntersecoes(float xMin, float yMin, float xMax, float yMax, float a, float b);

  bool getPontoCurva(float pontos[], no *p);
};
