#include <iostream>
using namespace std;

#include "no.h"

no::no(float xMin, float yMin, float xMax, float yMax)
{
  this->xMin = xMin;
  this->yMin = yMin;
  this->xMax = xMax;
  this->yMax = yMax;

  primeiro = NULL;
  segundo = NULL;
  terceiro = NULL;
  quarto = NULL;
}

no::~no()
{
}

float no::getXmin() { return xMin; }
float no::getYmin() { return yMin; }
float no::getXmax() { return xMax; }
float no::getYmax() { return yMax; }

no *no::getPrimeiro() { return primeiro; }
no *no::getSegundo() { return segundo; }
no *no::getTerceiro() { return terceiro; }
no *no::getQuarto() { return quarto; }

void no::setXmin(float xMin) { this->xMin = xMin; }
void no::setYmin(float yMin) { this->yMin = yMin; }
void no::setXmax(float xMax) { this->xMax = xMax; }
void no::setYmax(float yMax) { this->yMax = yMax; }

void no::setPrimeiro(no *primeiro) { this->primeiro = primeiro; }
void no::setSegundo(no *segundo) { this->segundo = segundo; }
void no::setTerceiro(no *terceiro) { this->terceiro = terceiro; }
void no::setQuarto(no *quarto) { this->quarto = quarto; }