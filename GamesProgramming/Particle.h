#pragma once
#include "Shape.h"

class Particle : public Shape
{
	public:
		Particle(vector position,float mass, int life);
		bool isAlive();
	private:
		int lifespan;
};