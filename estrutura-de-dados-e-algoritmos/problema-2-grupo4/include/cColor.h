#pragma once

#include <iostream>

typedef enum 	{	WHITE,
					BLACK,
					RED,
					GREEN,
					BLUE,
					MAGENTA,
					CIAN,
					YELLOW,
					GRAY
				} eColor;


class cColor {	

	float r;
	float g;
	float b;

public:

	cColor();
	cColor(float r, float g, float b); 
	cColor(eColor c); 

	void setColor(cColor c);

	void setR(float r);
	float getR();

	void setG(float g);
	float getG();

	void setB(float b);
	float getB();
	
	friend std::ostream &operator<<( std::ostream &output, const cColor &c );
};
