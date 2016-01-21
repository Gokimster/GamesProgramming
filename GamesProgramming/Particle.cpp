#include "Particle.h"

Particle::Particle(vector position, int lifespan) :Shape(position) {
	this->lifespan = lifespan;
}

bool Particle::isAlive()
{
	return ( lifespan > 0);
}