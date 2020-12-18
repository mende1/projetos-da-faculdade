#pragma once

#include <iostream>

#include "cColor.h"
#include "cPoint.h"

class cCircle {

    cPoint pCenter;
    float radius;

    cColor 	qColor;

    public:

        cCircle();
        cCircle(cPoint c, float radius);
        cCircle(cPoint c, float radius, cColor qc);

        void setCenter(cPoint c);
        cPoint getCenter();

        void setRadius(float r);
        float getRadius();

        void setCircleColor(cColor c);
        cColor getCircleColor();
};