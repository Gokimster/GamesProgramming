#pragma once
#include "Boid.h"

class BoidsManager
{
public:
	BoidsManager(vector pos, float boidSpeed, float nSize);
	int boids_no = 360;
	Boid boids[360];
	void updateBoids(int dt, int posBounds);
private:
	void initBoids();
	vector pos;
	float nSize;
	float boidSpeed;
};