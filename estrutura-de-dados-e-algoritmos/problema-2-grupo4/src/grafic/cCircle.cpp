#include <iostream>

#include "cCircle.h"

/*************************************************/ 
cCircle::cCircle () {

    pCenter     =   cPoint();
    radius      =   0;
}

/*************************************************/ 
cCircle::cCircle (cPoint c, float r) {

    pCenter.setCoords(c);
    radius  =   r;
}

/*************************************************/ 
cCircle::cCircle (cPoint c, float r, cColor qc) {

    pCenter.setCoords(c);
    radius  =   r;

    qColor.setColor(qc);
}

/*************************************************/ 
void cCircle::setCenter (cPoint c) {

    pCenter.setCoords(c);
}

/*************************************************/ 
cPoint cCircle::getCenter () {

    return pCenter;
}

/*************************************************/
void cCircle::setRadius (float r) {

    radius  =   r;
}

/*************************************************/
float cCircle::getRadius () {

    return radius;
}

/*************************************************/
void cCircle::setCircleColor (cColor c) {

    qColor.setColor(c);
}

/*************************************************/
cColor cCircle::getCircleColor () {

    return qColor;
}