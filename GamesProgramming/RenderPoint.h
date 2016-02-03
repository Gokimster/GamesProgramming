#pragma once
#include "Shape.h"
#include <glut.h>
class RenderPoint
{
	public:
		static void render(Shape b, vector color, float alpha = 1);
};