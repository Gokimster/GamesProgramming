#pragma once
#include "Shape.h"

class Particle : public Shape
{
	public:
		Particle(vector position,float mass, float life);
		bool isAlive();
		void update(int dt);
	private:
		float lifespan;
		float currLife;
};