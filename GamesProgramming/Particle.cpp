#include "stdafx.h"
#include "Particle.h"

Particle::Particle(vector position, float mass, int lifespan):Shape(position, mass) {
	this->lifespan = lifespan;
	this->currLife = lifespan;
}

bool Particle::isAlive()
{
	return ( lifespan > 0);
}

void Particle::update(int dt)
{
	Shape::updatePosition(dt);
	currLife - dt / 1000;
}