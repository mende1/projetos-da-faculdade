#pragma once

#include <iostream>

#include "cColor.h"
#include "cPoint.h"

class cQuad {	

	cPoint 	pMin;
	cPoint 	pMax;
	cColor 	qColor;
	bool 	fill = false;

	public:

		cQuad();
		cQuad(cPoint p0, cPoint p1); 
		cQuad(cPoint p0, cPoint p1, cColor c); 

		void 	setMinPoint(cPoint p);
		cPoint 	getMinPoint();
		
		void 	setMaxPoint(cPoint p);
		cPoint 	getMaxPoint();

		void 	setQuadColor(cColor	c);
		cColor 	getQuadColor();

		friend std::ostream &operator<<( std::ostream &output, const cQuad &q );

};
