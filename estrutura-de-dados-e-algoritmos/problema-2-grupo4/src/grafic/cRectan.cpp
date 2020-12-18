#include <iostream>

#include "cRectan.h"

/******************************************************************/
cRectan::cRectan () {

    pA   =  cPoint();
    pB   =  cPoint();
    pC   =  cPoint();
    pD   =  cPoint();
}

/******************************************************************/
cRectan::cRectan (cPoint p0, cPoint p1, cPoint p2, cPoint p3) {

    pA.setCoords(p0);
    pB.setCoords(p1);
    pC.setCoords(p2);
    pD.setCoords(p3);

    qColor = cColor();
}

/******************************************************************/
cRectan::cRectan (cPoint p0, cPoint p1, cPoint p2, cPoint p3, cColor c) {

    pA.setCoords(p0);
    pB.setCoords(p1);
    pC.setCoords(p2);
    pD.setCoords(p3);

    qColor.setColor(c);
}

/******************************************************************/
void cRectan::setPointA (cPoint p) {

    pA.setCoords(p);
}

/******************************************************************/
cPoint cRectan::getPointA () {

    return pA;
}

/******************************************************************/
void cRectan::setPointB (cPoint p) {

    pB.setCoords(p);
}

/******************************************************************/
cPoint cRectan::getPointB () {

    return pB;
}

/******************************************************************/
void cRectan::setPointC (cPoint p) {

    pC.setCoords(p);
}

/******************************************************************/
cPoint cRectan::getPointC () {

    return pC;
}

/******************************************************************/
void cRectan::setPointD (cPoint p) {

    pD.setCoords(p);
}

/******************************************************************/
cPoint cRectan::getPointD () {

    return pD;
}

/******************************************************************/
void cRectan::setRectanColor(cColor c) {

		qColor.setColor(c);
}

/******************************************************************/
cColor cRectan::getRectanColor() {

	return qColor;
}
