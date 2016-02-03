#include "stdafx.h"
#include "RenderPoint.h"

void RenderPoint::render(Shape s, vector color, float alpha)
{
	glColor4f(color.x, color.y, color.z, alpha);
	glVertex3f(s.pos.x, s.pos.y, s.pos.z);
}
