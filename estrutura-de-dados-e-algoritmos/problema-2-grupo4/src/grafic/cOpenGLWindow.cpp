#include <iostream>
#include <GL/glut.h>
#include <math.h>

#include "cOpenGLWindow.h"
		

/// ***********************************************************************
/// ** 
/// ***********************************************************************
cOpenGLWindow::cOpenGLWindow() {

	wWidth 	= 300;
	wHeight = 300;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
cOpenGLWindow::cOpenGLWindow(int w, int h) {

	wWidth 	= w;
	wHeight = h;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::setDomain(cQuad d) {

	domain = d;

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::init(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (wWidth, wHeight);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("QuadTree - Ray Tracing - Estrutura de Dados");

    glutDisplayFunc(cOpenGLWindow::display);
	glutReshapeFunc(cOpenGLWindow::reshape);
    glutKeyboardFunc(cOpenGLWindow::keyboard);
    glutMouseFunc(cOpenGLWindow::mouse);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    currentInstance = this;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::mainLoop() {

    glutMainLoop();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

extern "C" 
void cOpenGLWindow::display() {

	cPoint 	min	= currentInstance->domain.getMinPoint(),
			max = currentInstance->domain.getMaxPoint();

    glClear(GL_COLOR_BUFFER_BIT); 
    
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f( min.getX(), min.getY());
		glVertex2f( max.getX(), max.getY());
		
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f( max.getX(), min.getY());
		glVertex2f( min.getX(), max.getY());
	glEnd();   

	glutSwapBuffers();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::setDisplayFunc(void (*f)(void)) {

    glutDisplayFunc(f);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::setDisplayFuncDefault() {

    glutDisplayFunc(cOpenGLWindow::display);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

extern "C" 
void cOpenGLWindow::keyboard(unsigned char key, int x, int y) { 

	switch (key) {
		case 27		: 	exit(0);
						break;
		}

	glutPostRedisplay();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::setKeyboardFunc(void (*f)(unsigned char key, int x, int y)) { 

    glutKeyboardFunc(f);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

extern "C" 
void cOpenGLWindow::reshape(int w, int h) {

	currentInstance->wWidth = w;
	currentInstance->wHeight = h;

	glViewport(0, 0, (GLsizei) currentInstance->wWidth, (GLsizei) currentInstance->wHeight); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	gluOrtho2D(	currentInstance->domain.getMinPoint().getX()*1.1, 
				currentInstance->domain.getMaxPoint().getX()*1.1,  
				currentInstance->domain.getMinPoint().getY()*1.1, 
				currentInstance->domain.getMaxPoint().getY()*1.1);

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

extern "C" 
void cOpenGLWindow::mouse(int button, int button_state, int x, int y) {

	switch (button) {
		
		case GLUT_LEFT_BUTTON	: 	std::cout << "Mouse Left Button\n"; 
									break;

		case GLUT_RIGHT_BUTTON	:	std::cout << "Mouse Right Button\n"; 
									break;
		}

	glutPostRedisplay();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::setMouseFunc(void (*f)(int button, int button_state, int x, int y)) {

	glutMouseFunc(f);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::clear() {

    glClear(GL_COLOR_BUFFER_BIT); 
}

void cOpenGLWindow::draw() {

	glutSwapBuffers();
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void cOpenGLWindow::drawPoint(cPoint P) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(P.getColor().getR(), P.getColor().getG(), P.getColor().getB());

    glBegin(GL_POINTS);
		glVertex2f(P.getX(), P.getY());
    glEnd();   

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::drawLine(cPoint P0, cPoint P1) {

    glBegin(GL_LINES);

		glColor3f(P0.getColor().getR(), P0.getColor().getG(), P0.getColor().getB());
		glVertex2f(P0.getX(), P0.getY());

		glColor3f(P1.getColor().getR(), P1.getColor().getG(), P1.getColor().getB());
		glVertex2f(P1.getX(), P1.getY());

    glEnd(); 
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::drawQuad(cQuad Q) {

	cColor 	qc 	= Q.getQuadColor();
	cPoint 	min = Q.getMinPoint(),
			max = Q.getMaxPoint();

	glColor3f(qc.getR(), qc.getG(), qc.getB());

    glBegin(GL_QUADS);
		glVertex2f(min.getX(), min.getY());
		glVertex2f(max.getX(), min.getY()); 
		glVertex2f(max.getX(), max.getY()); 
		glVertex2f(min.getX(), max.getY());
    glEnd(); 

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::drawTriangle(cTriangle T) {

	cColor	qc  = T.getTriangleColor();
	cPoint	pA  = T.getPointA(),
			pB  = T.getPointB(),
			pC  = T.getPointC();

	glColor3f(qc.getR(), qc.getG(), qc.getB());

	glBegin(GL_TRIANGLES);
		glVertex2f(pA.getX(), pA.getY());
		glVertex2f(pB.getX(), pB.getY()); 
		glVertex2f(pC.getX(), pC.getY()); 
    glEnd(); 
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::drawRectan(cRectan R) {

	cColor 	qc  =  R.getRectanColor();
	cPoint 	pA  =  R.getPointA(),
			pB  =  R.getPointB(),
			pC  =  R.getPointC(),
			pD  =  R.getPointD();

	glColor3f(qc.getR(), qc.getG(), qc.getB());

    glBegin(GL_POLYGON);
		glVertex2f(pA.getX(), pA.getY());
		glVertex2f(pB.getX(), pB.getY()); 
		glVertex2f(pC.getX(), pC.getY()); 
		glVertex2f(pD.getX(), pD.getY());
    glEnd(); 

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cOpenGLWindow::drawCircle (cCircle C) {

	cColor	qc		=	C.getCircleColor();
	cPoint	pCenter = 	C.getCenter();
	float	r		= 	C.getRadius();
	double	pi		= 	3.142;
	float 	xC		=	pCenter.getX();
	float 	yC		=	pCenter.getY();
	float	theta;

	glColor3f(qc.getR(), qc.getG(), qc.getB());

	glBegin(GL_POLYGON);
		
		for (int i=0; i<360; i++) {
			theta = i * pi / 180;

			glVertex2f(xC + r * cos(theta), yC + r * sin(theta));
		}

    glEnd(); 
}