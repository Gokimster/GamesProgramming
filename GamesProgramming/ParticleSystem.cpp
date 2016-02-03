#include "stdafx.h"
#include "ParticleSystem.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <ctime>
#include<random>
ParticleSystem::ParticleSystem(vector pos, float particleLife, float particleVelocity)
{
	this->pos = pos;
	this->particleLife = particleLife;
	this->particleVelocity = particleVelocity;
	initParticleSystem();
}

void ParticleSystem::initParticleSystem()
{
	srand(static_cast <unsigned> (time(0)));
	//particles = new array<Particle, 360>();
	for (int i = 0; i < particle_no; i++)
	{
		particles[i] = Particle(pos, 0.1, particleLife);
		float angle = i * M_PI / 180;
		float c = cos(angle);
		float s = sin(angle);
		particles[i].addForce(vector(c, s, 0.0) * (particleVelocity + (1.0 + (rand() / (RAND_MAX / (-1.0 - 1.0))))));
	}
}

void ParticleSystem::updateParticles(int dt)
{
	for (int i = 0; i < particle_no; i++)
	{
		if (particles[i].isAlive())
		{
			particles[i].update(dt);
		}
		else {
			particles[i].pos = pos;
			particles[i].currLife = particleLife;
		}
	}
}