#include "stdafx.h"
#include "BoidsManager.h"

BoidsManager::BoidsManager(vector pos, float boidSpeed)
{
	this->pos = pos;
	this->boidSpeed = boidSpeed;
}

void BoidsManager::updateBoids(int dt)
{
	for (int i = 0; i < boids_no; i++)
	{
		boids[i].update(dt, boids, boids_no);
	}
}

void BoidsManager::initBoids()
{
	for (int i = 0; i < boids_no; i++)
	{
		boids[i] = Boid(pos, boidSpeed);
	}
}
