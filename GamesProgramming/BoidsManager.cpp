#include "stdafx.h"
#include "BoidsManager.h"

BoidsManager::BoidsManager(vector pos)
{
	this->pos = pos;
}

void BoidsManager::updateBoids(int dt)
{
	for (int i = 0; i < boids_no; i++)
	{
		boids[i].update(dt);
	}
}

void BoidsManager::initBoids()
{
	for (int i = 0; i < boids_no; i++)
	{
		boids[i] = Boid(pos);
	}
}
