#pragma once
#include "Shape.h"

class Boid : public Shape
{
	public:
		Boid(vector position, float speed);
		Boid();
		void update(int dt, Boid neighbourhood[], int nSize);
		vector alignment(Boid neighbourhood[], int nSize);
		vector cohesion(Boid neighbourhood[], int nSize);
		vector separation(Boid neighbourhood[], int nSize);
	private:
		float speed;
};