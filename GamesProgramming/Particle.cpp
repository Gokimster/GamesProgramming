#include "stdafx.h"
#include "Particle.h"

Particle::Particle(vector position, float mass, int lifespan):Shape(position, mass) {
	this->lifespan = lifespan;
}

bool Particle::isAlive()
{
	return ( lifespan > 0);
}