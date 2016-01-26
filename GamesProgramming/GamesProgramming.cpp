// GamesProgramming.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "glut.h"
#include "Ball.h"

Ball *b;

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSolidSphere(b->radius, 20.0, 20.0);
	glFlush();
}

void lab1(int argc, char **argv)
{
	b = new Ball(vector(0, 0, 0), 1.0f, 1.0f);
	GLUquadric *qobj = gluNewQuadric();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("pendulum");
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();\
}

int main(int argc, char **argv)
{
	lab1(argc, argv);
}

