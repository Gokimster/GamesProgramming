#pragma once
#include "Ball.h"
class RenderManager
{
	public:
		static void renderBall(Ball b);
		static void renderPoint(Shape s, vector color, float alpha = 1);
		static void clear();
		static void initGL();
};