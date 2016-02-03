#pragma once
#include "Shape.h"

class Particle : public Shape
{
	public:
		Particle();
		Particle(vector position,float mass, float life);
		bool isAlive();
		void update(int dt);
		float lifespan;
		float currLife;
};