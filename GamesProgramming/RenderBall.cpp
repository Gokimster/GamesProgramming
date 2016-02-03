#include "stdafx.h"
#include "RenderBall.h"
#include <glut.h>

void RenderBall::render(Ball b)
{
	glLoadIdentity();
	glTranslatef(b.pos.x, b.pos.y, b.pos.z);
	glutWireSphere(b.radius, 20.0, 20.0);
}
