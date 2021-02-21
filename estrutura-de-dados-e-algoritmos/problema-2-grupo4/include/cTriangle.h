#pragma once

#include <iostream>

#include "cColor.h"
#include "cPoint.h"

class cTriangle {

    cPoint pA;
    cPoint pB;
    cPoint pC;
    cColor 	qColor;

    public:

        cTriangle();
        cTriangle(cPoint pA, cPoint pB, cPoint pC);
        cTriangle(cPoint pA, cPoint pB, cPoint pC, cColor qColor);

        void 	setPointA(cPoint p);
		cPoint 	getPointA();
		
		void 	setPointB(cPoint p);
		cPoint 	getPointB();

		void 	setPointC(cPoint p);
		cPoint 	getPointC();

		void 	setTriangleColor(cColor	c);
		cColor 	getTriangleColor();
};