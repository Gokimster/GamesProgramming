#pragma once
#include "Particle.h"
#include <array>

class ParticleSystem
{
	public:
		ParticleSystem(vector pos, float particleLife, float particleVelocity);
		int particle_no = 360;
		Particle particles[360];
		void updateParticles(int dt);
	private:
		void initParticleSystem();
		vector pos;
		float particleLife;
		float particleVelocity;
};