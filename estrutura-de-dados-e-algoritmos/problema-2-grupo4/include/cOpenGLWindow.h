#pragma once

#include <iostream>

#include "cPoint.h"
#include "cQuad.h"
#include "cTriangle.h"
#include "cRectan.h"
#include "cCircle.h"

class cOpenGLWindow {

private:
	int		wWidth,
			wHeight;

	cQuad 	domain;
	
public: 

	cOpenGLWindow();
	cOpenGLWindow(int w, int h);

	void setDomain(cQuad d);

	void init(int argc, char** argv);
	void mainLoop();
	void clear();
	void draw();

	static void display();
	static void keyboard(unsigned char key, int x, int y);
	static void mouse(int button, int button_state, int x, int y);
	static void reshape(int w, int h);

	void setDisplayFunc(void (*f)(void));
	void setDisplayFuncDefault();
	void setKeyboardFunc(void (*f)(unsigned char key, int x, int y));
	void setMouseFunc(void (*f)(int button, int button_state, int x, int y));
	void setReshapeFunc(void (*f)(int button, int button_state, int x, int y));

	void drawPoint(cPoint P);
	void drawLine(cPoint P0, cPoint P1);
	void drawQuad(cQuad Q);
	void drawTriangle(cTriangle T);
	void drawRectan(cRectan R);
	void drawCircle(cCircle C);

};

static cOpenGLWindow* currentInstance;


