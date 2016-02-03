#include "stdafx.h"
#include "Particle.h"

Particle::Particle(vector position, float mass, float lifespan):Shape(position, mass) {
	this->lifespan = lifespan;
	this->currLife = lifespan;
}

Particle::Particle()
{

}

bool Particle::isAlive()
{
	return ( currLife > 0);
}

void Particle::update(int dt)
{
	pos = pos + (velocity*((float)dt / 1000));
	if (dt > 0)
	{
		currLife -= (float)dt / (float)1000;
	}
}