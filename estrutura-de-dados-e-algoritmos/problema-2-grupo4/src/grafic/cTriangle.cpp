#include <iostream>

#include "cTriangle.h"

/******************************************************************/
cTriangle::cTriangle () {

    pA   =  cPoint();
    pB   =  cPoint();
    pC   =  cPoint();
}

/******************************************************************/
cTriangle::cTriangle (cPoint p0, cPoint p1, cPoint p2) {

    pA.setCoords(p0);
    pB.setCoords(p1);
    pC.setCoords(p2);

    qColor = cColor();
}

/******************************************************************/
cTriangle::cTriangle (cPoint p0, cPoint p1, cPoint p2, cColor c) {

    pA.setCoords(p0);
    pB.setCoords(p1);
    pC.setCoords(p2);

    qColor.setColor(c);
}

/******************************************************************/
void cTriangle::setPointA (cPoint p) {

    pA.setCoords(p);
}

/******************************************************************/
cPoint cTriangle::getPointA () {

    return pA;
}

/******************************************************************/
void cTriangle::setPointB (cPoint p) {

    pB.setCoords(p);
}

/******************************************************************/
cPoint cTriangle::getPointB () {

    return pB;
}

/******************************************************************/
void cTriangle::setPointC (cPoint p) {

    pC.setCoords(p);
}

/******************************************************************/
cPoint cTriangle::getPointC () {

    return pC;
}

/******************************************************************/
void cTriangle::setTriangleColor(cColor c) {

		qColor.setColor(c);
}

/******************************************************************/
cColor cTriangle::getTriangleColor() {

	return qColor;
}
