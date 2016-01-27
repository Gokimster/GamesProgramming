// GamesProgramming.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "glut.h"
#include "Ball.h"
#include <ctime>
using namespace std;

Ball *b;
time_t oldTime = 0;
time_t newTime = 0;

int getDeltaTime()
{
	oldTime = newTime;
	newTime = time(0);
	if (oldTime == 0)
	{
		oldTime = newTime;
	}
	return newTime - oldTime;
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void displayBall()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(b->pos.x, b->pos.y, b->pos.z);
	glutSolidSphere(b->radius, 20.0, 20.0);
	glFlush();
}

void displayParticles()
{
}

void idleParticles()
{
	int dt = getDeltaTime();
	b->updatePosition(dt);
	glutPostRedisplay();
}

bool checkBallBottom()
{
	if (b->pos.y <= (-10 + b->radius))
	{
		glutIdleFunc(idleParticles);
		glutDisplayFunc(displayParticles);
		return true;
	}
	return false;
}

void idleBallFalling()
{
	if (!checkBallBottom())
	{
		int dt = getDeltaTime();
		b->updatePosition(dt);
		glutPostRedisplay();
	}
}

void lab1(int argc, char **argv)
{
	b = new Ball(vector(0.0, 10.0, 0.0), 1.0f, 1.0f);
	GLUquadric *qobj = gluNewQuadric();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lab1");
	glutDisplayFunc(displayBall);
	glutIdleFunc(idleBallFalling);
	initGL();
	glutMainLoop();\
}

int main(int argc, char **argv)
{
	lab1(argc, argv);
}

