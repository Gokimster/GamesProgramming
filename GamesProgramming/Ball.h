#pragma once
#include "Shape.h"

class Ball : public Shape
{
	public:
		float radius;
		Ball(vector position, float mass, float radius);
		Ball();
		void updatePosition(int dt);
};