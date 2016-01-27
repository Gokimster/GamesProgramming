#pragma once
#include "Particle.h"
#include <array>;

class ParticleSystem
{
	public:
		ParticleSystem(vector pos, float particleLife, float particleVelocity);
		std::array <Particle, 360> particles;
	private:
		void initParticleSystem();
		vector pos;
		float particleLife;
		float particleVelocity;
};