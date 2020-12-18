#include <math.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "arvore.h"
#include "cOpenGLWindow.h"

float precisao = 0.0002;
float precisaoTracing = 0.02;

arvore::arvore(no *raiz) { this->raiz = raiz; }

arvore::~arvore() { percorreArvoreDeletando(raiz); };

no *arvore::getRaiz() { return raiz; }
void arvore::setRaiz(no *raiz) { this->raiz = raiz; }

void arvore::criaArvore(no *root, int funcao)
{
  float priPontos[4];
  float segPontos[4];
  float terPontos[4];
  float quarPontos[4];

  float xMin, yMin, xMax, yMax;
  float xMedia = (root->getXmin() + root->getXmax()) / 2.0;
  float yMedia = (root->getYmin() + root->getYmax()) / 2.0;

  // Primeiro Quadrante
  xMin = xMedia;
  yMin = yMedia;
  xMax = root->getXmax();
  yMax = root->getYmax();
  no *p = new no(xMin, yMin, xMax, yMax);
  root->setPrimeiro(p);

  // Segundo Quadrante
  xMin = root->getXmin();
  yMin = yMedia;
  xMax = xMedia;
  yMax = root->getYmax();
  no *s = new no(xMin, yMin, xMax, yMax);
  root->setSegundo(s);

  // Terceiro Quadrante
  xMin = root->getXmin();
  yMin = root->getYmin();
  xMax = xMedia;
  yMax = yMedia;
  no *t = new no(xMin, yMin, xMax, yMax);
  root->setTerceiro(t);

  // Quarto Quadrante
  xMin = xMedia;
  yMin = root->getYmin();
  xMax = root->getXmax();
  yMax = yMedia;
  no *q = new no(xMin, yMin, xMax, yMax);
  root->setQuarto(q);

  // Primeiro quadrante
  calculaFuncao(p, priPontos, funcao);

  // Segundo quadrante
  calculaFuncao(s, segPontos, funcao);

  // Terceiro Quadrante
  calculaFuncao(t, terPontos, funcao);

  // Quarto Quadrante
  calculaFuncao(q, quarPontos, funcao);
  bool cross = false;

  // Primeiro Quadrante
  cross = estaDentro(priPontos, p);
  if (cross && (p->getXmax() - p->getXmin()) >= precisao)
  {
    criaArvore(p, funcao);
  }
  // Segundo Quadrante
  cross = estaDentro(segPontos, s);
  if (cross && (s->getXmax() - s->getXmin()) >= precisao)
  {
    criaArvore(s, funcao);
  }

  // Terceiro Quadrante
  cross = estaDentro(terPontos, t);
  if (cross && (t->getXmax() - t->getXmin()) >= precisao)
  {
    criaArvore(t, funcao);
  }

  // Quarto Quadrante
  cross = estaDentro(quarPontos, q);
  if (cross && (q->getXmax() - q->getXmin()) >= precisao)
  {
    criaArvore(q, funcao);
  }
}

void arvore::desenhaArvore(no *noAtual, bool quadric, int funcao, cOpenGLWindow win)
{

  if (noAtual != NULL)
  {

    if (quadric)
      win.drawQuad(cQuad(cPoint(noAtual->getXmin(), noAtual->getYmin()),
                         cPoint(noAtual->getXmax(), noAtual->getYmax()), MAGENTA));

    float pontos[4];
    calculaFuncao(noAtual, pontos, funcao);
    desenhaPonto(pontos, noAtual, win);

    desenhaArvore(noAtual->getPrimeiro(), quadric, funcao, win);
    desenhaArvore(noAtual->getSegundo(), quadric, funcao, win);
    desenhaArvore(noAtual->getTerceiro(), quadric, funcao, win);
    desenhaArvore(noAtual->getQuarto(), quadric, funcao, win);
  }
}

void arvore::buscaRayTracing(no *noAtual, float a, float b, int funcao, int ray, bool &achou, cOpenGLWindow win)
{

  bool tocaAresta;
  bool eFolha;

  if (achou)
  {
    return;
  }

  if (noAtual != NULL)
  {

    vector<float> intersecoes = getIntersecoes(noAtual->getXmin(), noAtual->getYmin(), noAtual->getXmax(), noAtual->getYmax(), a, b);

    tocaAresta =
        (intersecoes[0] >= noAtual->getXmin() && intersecoes[0] <= noAtual->getXmax()) ||
        (intersecoes[1] >= noAtual->getXmin() && intersecoes[1] <= noAtual->getXmax()) ||
        (intersecoes[2] >= noAtual->getYmin() && intersecoes[2] <= noAtual->getYmax()) ||
        (intersecoes[3] >= noAtual->getYmin() && intersecoes[3] <= noAtual->getYmax());

    if (tocaAresta)
    {
      eFolha =
          (noAtual->getPrimeiro() == NULL) &&
          (noAtual->getSegundo() == NULL) &&
          (noAtual->getTerceiro() == NULL) &&
          (noAtual->getQuarto() == NULL);

      if (eFolha)
      {

        win.drawQuad(cQuad(cPoint(noAtual->getXmin(), noAtual->getYmin()),
                           cPoint(noAtual->getXmax(), noAtual->getYmax()), CIAN));

        float pontos[4];
        calculaFuncao(noAtual, pontos, funcao);
        achou = getPontoCurva(pontos, noAtual);
      }

      if (!achou)
      {
        switch (ray)
        {

        case 0:
          buscaRayTracing(noAtual->getPrimeiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getQuarto(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getTerceiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getSegundo(), a, b, funcao, ray, achou, win);
          break;

        case 1:
          buscaRayTracing(noAtual->getTerceiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getQuarto(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getPrimeiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getSegundo(), a, b, funcao, ray, achou, win);
          break;

        case 2:
          buscaRayTracing(noAtual->getSegundo(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getTerceiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getQuarto(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getPrimeiro(), a, b, funcao, ray, achou, win);
          break;

        case 3:
          buscaRayTracing(noAtual->getQuarto(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getTerceiro(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getSegundo(), a, b, funcao, ray, achou, win);
          buscaRayTracing(noAtual->getPrimeiro(), a, b, funcao, ray, achou, win);
          break;
        }
      }
    }
  }
  return;
}

void arvore::percorreArvoreDeletando(no *noAtual)
{
  if (noAtual != NULL)
  {
    percorreArvoreDeletando(noAtual->getPrimeiro());
    percorreArvoreDeletando(noAtual->getSegundo());
    percorreArvoreDeletando(noAtual->getTerceiro());
    percorreArvoreDeletando(noAtual->getQuarto());
    delete noAtual;
  }
}

void arvore::calculaFuncao(no *p, float pontos[], int funcao)
{
  // Translação
  float x0 = 0;
  float y0 = 0;

  switch (funcao)
  {
  case 0:
  {
    // Circulo
    // x2 + y2 -r2 = 0

    float raio = 1;

    pontos[0] = pow((p->getXmax() - x0), 2) + pow((p->getYmax() - y0), 2) -
                pow(raio, 2);
    pontos[1] = pow((p->getXmin() - x0), 2) + pow((p->getYmax() - y0), 2) -
                pow(raio, 2);
    pontos[2] = pow((p->getXmin() - x0), 2) + pow((p->getYmin() - y0), 2) -
                pow(raio, 2);
    pontos[3] = pow((p->getXmax() - x0), 2) + pow((p->getYmin() - y0), 2) -
                pow(raio, 2);
  }
  break;

  case 1:
  {
    // Cardioid
    //(x2 + y2 − 2ax)2 -4a2 (x2 + y2) = 0
    float a = 1;

    pontos[0] =
        pow(pow((p->getXmax() - x0), 2) + pow((p->getYmax() - y0), 2) -
                2 * a * (p->getXmax() - x0),
            2) -
        4 * pow(a, 2) *
            (pow((p->getXmax() - x0), 2) + pow((p->getYmax() - y0), 2));
    pontos[1] =
        pow(pow((p->getXmin() - x0), 2) + pow((p->getYmax() - y0), 2) -
                2 * a * (p->getXmin() - x0),
            2) -
        4 * pow(a, 2) *
            (pow((p->getXmin() - x0), 2) + pow((p->getYmax() - y0), 2));
    pontos[2] =
        pow(pow((p->getXmin() - x0), 2) + pow((p->getYmin() - y0), 2) -
                2 * a * (p->getXmin() - x0),
            2) -
        4 * pow(a, 2) *
            (pow((p->getXmin() - x0), 2) + pow((p->getYmin() - y0), 2));
    pontos[3] =
        pow(pow((p->getXmax() - x0), 2) + pow((p->getYmin() - y0), 2) -
                2 * a * (p->getXmax() - x0),
            2) -
        4 * pow(a, 2) *
            (pow((p->getXmax() - x0), 2) + pow((p->getYmin() - y0), 2));
  }
  break;

  case 2:
  {
    // Parabola
    // x2-y = 0

    pontos[0] = pow(p->getXmax() - x0, 2) - (p->getYmax() - y0);
    pontos[1] = pow(p->getXmin() - x0, 2) - (p->getYmax() - y0);
    pontos[2] = pow(p->getXmin() - x0, 2) - (p->getYmin() - y0);
    pontos[3] = pow(p->getXmax() - x0, 2) - (p->getYmin() - y0);
  }
  break;

  case 3:
  {
    // Pear Shaped Quartic
    // x4 - ax3 + b2y2 = 0

    float a = 2;
    float b = -2.2;

    pontos[0] = pow(p->getXmax() - x0, 4) - a * pow(p->getXmax() - x0, 3) +
                pow(b, 2) * pow(p->getYmax() - y0, 2);
    pontos[1] = pow(p->getXmin() - x0, 4) - a * pow(p->getXmin() - x0, 3) +
                pow(b, 2) * pow(p->getYmax() - y0, 2);
    pontos[2] = pow(p->getXmin() - x0, 4) - a * pow(p->getXmin() - x0, 3) +
                pow(b, 2) * pow(p->getYmin() - y0, 2);
    pontos[3] = pow(p->getXmax() - x0, 4) - a * pow(p->getXmax() - x0, 3) +
                pow(b, 2) * pow(p->getYmin() - y0, 2);
  }
  break;

  case 4:
  {
    // Lame Curves
    // (x/a)n +(y/b)n -1 = 0

    float a = 2;
    float b = 1;
    float n = 4;

    pontos[0] = pow(((p->getXmax() - x0) / a), n) +
                pow(((p->getYmax() - y0) / b), n) - 1;
    pontos[1] = pow(((p->getXmin() - x0) / a), n) +
                pow(((p->getYmax() - y0) / b), n) - 1;
    pontos[2] = pow(((p->getXmin() - x0) / a), n) +
                pow(((p->getYmin() - y0) / b), n) - 1;
    pontos[3] = pow(((p->getXmax() - x0) / a), n) +
                pow(((p->getYmin() - y0) / b), n) - 1;
  }
  break;

  case 5:
  {
    // Bicorn
    // y2 (a2 - x2) - (x2 + 2ay - a2)2 = 0

    float a = 1.6;

    // Translação
    x0 = 0.5;
    y0 = -1;

    pontos[0] =
        pow(p->getYmax() - y0, 2) * (pow(a, 2) - pow(p->getXmax() - x0, 2)) -
        pow((pow(p->getXmax() - x0, 2) + 2 * a * (p->getYmax() - y0) -
             pow(a, 2)),
            2);
    pontos[1] =
        pow(p->getYmax() - y0, 2) * (pow(a, 2) - pow(p->getXmin() - x0, 2)) -
        pow((pow(p->getXmin() - x0, 2) + 2 * a * (p->getYmax() - y0) -
             pow(a, 2)),
            2);
    pontos[2] =
        pow(p->getYmin() - y0, 2) * (pow(a, 2) - pow(p->getXmin() - x0, 2)) -
        pow((pow(p->getXmin() - x0, 2) + 2 * a * (p->getYmin() - y0) -
             pow(a, 2)),
            2);
    pontos[3] =
        pow(p->getYmin() - y0, 2) * (pow(a, 2) - pow(p->getXmax() - x0, 2)) -
        pow((pow(p->getXmax() - x0, 2) + 2 * a * (p->getYmin() - y0) -
             pow(a, 2)),
            2);
  }
  break;

  case 6:
  {
    // Trifolium
    //(x2+y2)2 -ax(x2 - 3y2) = 0
    float a = 2;

    pontos[0] =
        pow(pow((p->getXmax() - x0), 2) + pow((p->getYmax() - y0), 2), 2) -
        a * (p->getXmax() - x0) *
            (pow((p->getXmax() - x0), 2) - 3 * pow((p->getYmax() - y0), 2));
    pontos[1] =
        pow(pow((p->getXmin() - x0), 2) + pow((p->getYmax() - y0), 2), 2) -
        a * (p->getXmin() - x0) *
            (pow((p->getXmin() - x0), 2) - 3 * pow((p->getYmax() - y0), 2));
    pontos[2] =
        pow(pow((p->getXmin() - x0), 2) + pow((p->getYmin() - y0), 2), 2) -
        a * (p->getXmin() - x0) *
            (pow((p->getXmin() - x0), 2) - 3 * pow((p->getYmin() - y0), 2));
    pontos[3] =
        pow(pow((p->getXmax() - x0), 2) + pow((p->getYmin() - y0), 2), 2) -
        a * (p->getXmax() - x0) *
            (pow((p->getXmax() - x0), 2) - 3 * pow((p->getYmin() - y0), 2));
  }
  break;

  default:
    break;
  }
}

bool arvore::estaDentro(float pontos[], no *p)
{
  int contador = 0;

  for (int i = 0; i < 4; i++)
  {
    if (pontos[i] < -precisao)
      contador++;
    if (pontos[i] >= -precisao && pontos[i] <= precisao)
    {
      contador++;
    }
  }
  return (contador >= 1 && (contador <= 3));
}

void arvore::desenhaPonto(float pontos[], no *p, cOpenGLWindow win)
{
  for (int i = 0; i < 4; i++)
  {
    if (pontos[i] >= -precisao && pontos[i] <= precisao)
    {
      switch (i)
      {
      case 0:
        win.drawPoint(cPoint(p->getXmax(), p->getYmax(), YELLOW));
        break;
      case 1:
        win.drawPoint(cPoint(p->getXmin(), p->getYmax(), YELLOW));
        break;
      case 2:
        win.drawPoint(cPoint(p->getXmin(), p->getYmin(), YELLOW));
        break;
      default:
        win.drawPoint(cPoint(p->getXmax(), p->getYmin(), YELLOW));
        break;
      }
    }
  }
}

vector<float> arvore::getReta(float x0, float y0, float x1, float y1)
{
  float a = (y1 - y0) / (x1 - x0);
  float b = y0 - a * x0;
  return {a, b};
}

vector<float> arvore::getIntersecoes(float xMin, float yMin, float xMax, float yMax, float a, float b)
{
  float x, y;
  vector<float> intercecoes;

  // Interseçoes com x
  // x = (y-b)/a
  x = (yMin - b) / a;
  intercecoes.push_back(x);

  x = (yMax - b) / a;
  intercecoes.push_back(x);

  // Interseçoes com y
  //y = ax + b
  y = a * xMin + b;
  intercecoes.push_back(y);

  y = a * xMax + b;
  intercecoes.push_back(y);

  return intercecoes;
}

bool arvore::getPontoCurva(float pontos[], no *p)
{
  for (int i = 0; i < 4; i++)
  {
    if (pontos[i] >= -precisaoTracing && pontos[i] <= precisaoTracing)
    {
      return true;
    }
  }
  return false;
}