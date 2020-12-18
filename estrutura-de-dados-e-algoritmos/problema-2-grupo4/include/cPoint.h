#pragma once

#include "cColor.h"

class cPoint {	

	float 	xCoord;
	float 	yCoord;
	cColor 	pColor;

	public:

		cPoint();
		cPoint(float x, float y); 
		cPoint(float x, float y, cColor c); 
		cPoint(float x, float y, eColor c); 

		void 	setCoords(cPoint p);

		float 	getX();
		float 	getY();
		cColor 	getColor();

		friend std::ostream &operator<<( std::ostream &output, const cPoint &pt );

};
