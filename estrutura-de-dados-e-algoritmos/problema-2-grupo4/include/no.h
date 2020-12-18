#include <iostream>
using namespace std;

#include "cQuad.h"

class no
{
private:
  // Quadrado Completo
  float xMin, yMin; // ponto minimo
  float xMax, yMax; // ponto maximo

  // Quadrantes do Quadrado Completo
  no *primeiro;
  no *segundo;
  no *terceiro;
  no *quarto;

public:
  no(float xMin, float yMin, float xMax, float yMax);
  ~no();

  float getXmin();
  float getYmin();
  float getXmax();
  float getYmax();

  no *getPrimeiro();
  no *getSegundo();
  no *getTerceiro();
  no *getQuarto();

  void setXmin(float xMin);
  void setYmin(float yMin);
  void setXmax(float xMax);
  void setYmax(float yMax);

  void setPrimeiro(no *primeiro);
  void setSegundo(no *segundo);
  void setTerceiro(no *terceiro);
  void setQuarto(no *quarto);
};