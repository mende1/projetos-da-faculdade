#include <GL/glut.h>

#include <cmath>
#include <iostream>
#include <vector>

#include "arvore.h"
#include "cOpenGLWindow.h"
#include "cPoint.h"
#include "sCoordQuad.h"

cOpenGLWindow win(800, 800);
int count0 = 0;
int count1 = 0;

int funcao = 0;
int ray = 0;
bool quadric = false;
sCoordQuad rayTracing;

int *pFuncao = &funcao;
int *pRay = &ray;
bool *pQuadric = &quadric;
sCoordQuad *pRayTracing = &rayTracing;

float tamQuad = 4.0f;

no *root0 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *circulo = new arvore(root0);

no *root1 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *feijao = new arvore(root1);

no *root2 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *parabola = new arvore(root2);

no *root3 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *gota = new arvore(root3);

no *root4 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *lamecurve = new arvore(root4);

no *root5 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *bicorno = new arvore(root5);

no *root6 = new no(-tamQuad, -tamQuad, tamQuad, tamQuad);
arvore *flor = new arvore(root6);

no *root;
arvore *quadTree;

/// ***********************************************************************
/// **
/// ***********************************************************************

void draw(void) {
  win.clear();
  quadTree = circulo;
  root = root0;

  switch (funcao) {
    case 0:
      quadTree = circulo;
      root = root0;
      break;

    case 1:
      quadTree = feijao;
      root = root1;
      break;

    case 2:
      quadTree = parabola;
      root = root2;
      break;

    case 3:
      quadTree = gota;
      root = root3;
      break;

    case 4:
      quadTree = lamecurve;
      root = root4;
      break;

    case 5:
      quadTree = bicorno;
      root = root5;
      break;

    case 6:
      quadTree = flor;
      root = root6;
      break;

    default:
      break;
  }
  quadTree->desenhaArvore(root, quadric, funcao, win);
  bool achou = false;

  if (count0 != 0) {
    win.drawLine(cPoint(rayTracing.xMin, rayTracing.yMin, BLUE),
                 cPoint(rayTracing.xMax, rayTracing.yMax, RED));

    vector<float> reta = quadTree->getReta(rayTracing.xMin, rayTracing.yMin,
                                           rayTracing.xMax, rayTracing.yMax);
    quadTree->buscaRayTracing(root, reta[0], reta[1], funcao, ray, achou, win);
  }

  win.draw();
}

/// ***********************************************************************
/// **
/// ***********************************************************************

void myKeyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;

    case '0':
      *pFuncao = 0;
      win.setDisplayFunc(draw);
      break;

    case '1':
      *pFuncao = 1;
      win.setDisplayFunc(draw);
      break;

    case '2':
      *pFuncao = 2;
      win.setDisplayFunc(draw);
      break;

    case '3':
      *pFuncao = 3;
      win.setDisplayFunc(draw);
      break;

    case '4':
      *pFuncao = 4;
      win.setDisplayFunc(draw);
      break;

    case '5':
      *pFuncao = 5;
      win.setDisplayFunc(draw);
      break;

    case '6':
      *pFuncao = 6;
      win.setDisplayFunc(draw);
      break;
  }

  count0 = 0;

  glutPostRedisplay();
}

/// ***********************************************************************
/// **
/// ***********************************************************************

void myMouse(int button, int button_state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:

      if (count0 % 8 == 0) {
        sCoordQuad aux;

        aux.xMin = 5;
        aux.yMin = 4;
        aux.xMax = -5;
        aux.yMax = -5;

        *pRayTracing = aux;
        *pRay = 0;
      }
      if (count0 % 8 == 2) {
        sCoordQuad aux;

        aux.xMin = -5;
        aux.yMin = -5;
        aux.xMax = 5;
        aux.yMax = 4;

        *pRayTracing = aux;
        *pRay = 1;
      }
      if (count0 % 8 == 4) {
        sCoordQuad aux;

        aux.xMin = -5;
        aux.yMin = 4;
        aux.xMax = 5;
        aux.yMax = -5;

        *pRayTracing = aux;
        *pRay = 2;
      }
      if (count0 % 8 == 6) {
        sCoordQuad aux;

        aux.xMin = 5;
        aux.yMin = -5;
        aux.xMax = -5;
        aux.yMax = 4;

        *pRayTracing = aux;
        *pRay = 3;
      }

      count0++;
      win.setDisplayFunc(draw);
      break;

    case GLUT_RIGHT_BUTTON:

      if (count1 % 2 == 0) *pQuadric = !(*pQuadric);

      count1++;
      break;
  }

  glutPostRedisplay();
}

/// ***********************************************************************
/// **
/// ***********************************************************************

int main(int argc, char **argv) {
  win.setDomain(cQuad(cPoint(-4.0f, -4.0f), cPoint(4.0f, 4.0f), BLUE));

  win.init(argc, argv);

  circulo->criaArvore(root0, 0);
  feijao->criaArvore(root1, 1);
  parabola->criaArvore(root2, 2);
  gota->criaArvore(root3, 3);
  lamecurve->criaArvore(root4, 4);
  bicorno->criaArvore(root5, 5);
  flor->criaArvore(root6, 6);

  rayTracing.xMin = 5;
  rayTracing.yMin = 4;
  rayTracing.xMax = -5;
  rayTracing.yMax = -5;

  win.setKeyboardFunc(myKeyboard);
  win.setMouseFunc(myMouse);
  win.setDisplayFunc(draw);

  win.mainLoop();

  return 0;
}
