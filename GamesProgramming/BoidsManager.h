#pragma once
#include "Boid.h"

class BoidsManager
{
public:
	BoidsManager(vector pos, float boidSpeed);
	int boids_no = 360;
	Boid boids[360];
	void updateBoids(int dt);
private:
	void initBoids();
	vector pos;
	float boidSpeed;
};