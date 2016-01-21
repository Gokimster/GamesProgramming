#pragma once
#include "Shape.h"

class Particle : public Shape
{
	public:
		Particle(vector position, int life);
		bool isAlive();
	private:
		int lifespan;
};