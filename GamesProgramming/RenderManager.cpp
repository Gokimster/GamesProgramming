#include "stdafx.h"
#include "RenderManager.h"
#include <glut.h>

void RenderManager::renderBall(Ball b)
{
	glLoadIdentity();
	glTranslatef(b.pos.x, b.pos.y, b.pos.z);
	glutWireSphere(b.radius, 20.0, 20.0);
}

void RenderManager::renderPoint(Shape s, vector color, float alpha)
{
	glColor4f(color.x, color.y, color.z, alpha);
	glVertex3f(s.pos.x, s.pos.y, s.pos.z);
}

void RenderManager::initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void RenderManager::clear()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}
