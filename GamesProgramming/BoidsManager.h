#pragma once
#include "Boid.h"

class BoidsManager
{
public:
	BoidsManager(vector pos);
	int boids_no = 360;
	Boid boids[360];
	void updateBoids(int dt);
private:
	void initBoids();
	vector pos;
};