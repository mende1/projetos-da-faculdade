#pragma once

#include <iostream>

#include "cColor.h"
#include "cPoint.h"

class cRectan {

    cPoint pA;
    cPoint pB;
    cPoint pC;
    cPoint pD;
    cColor 	qColor;

    public:

        cRectan();
        cRectan(cPoint pA, cPoint pB, cPoint pC, cPoint pD);
        cRectan(cPoint pA, cPoint pB, cPoint pC, cPoint cD, cColor qColor);

        void 	setPointA(cPoint p);
		cPoint 	getPointA();
		
		void 	setPointB(cPoint p);
		cPoint 	getPointB();

		void 	setPointC(cPoint p);
		cPoint 	getPointC();

        void 	setPointD(cPoint p);
		cPoint 	getPointD();

		void 	setRectanColor(cColor c);
		cColor 	getRectanColor();
};