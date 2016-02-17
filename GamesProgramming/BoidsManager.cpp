#include "stdafx.h"
#include "BoidsManager.h"
#include <random>

BoidsManager::BoidsManager(vector pos, float boidSpeed, float nSize)
{
	this->pos = pos;
	this->boidSpeed = boidSpeed;
	this->nSize = nSize;
	initBoids();
}

void BoidsManager::updateBoids(int dt, int posBounds)
{
	for (int i = 0; i < boids_no; i++)
	{
		if (boids[i].pos.x < -10 || boids[i].pos.x > 10 || boids[i].pos.y < -10 || boids[i].pos.y > 10)
		{
			boids[i].pos.x = -boids[i].pos.x;
			boids[i].pos.y = -boids[i].pos.y;
		}
		Boid * neighbours = new Boid[360];
		int j = 0;
		Boid b = boids[i];
		for (int x = 0; x < boids_no; x++)
		{
			if (abs(b.pos.distance(boids[x].pos)) < nSize)
			{
				neighbours[j++] = boids[x];
			}
		}
		boids[i].update(dt, neighbours, j);
	}
}

void BoidsManager::initBoids()
{
	for (int i = 0; i < boids_no; i++)
	{
		boids[i] = Boid(pos, (boidSpeed + 1.0 + rand() / (RAND_MAX / (-1.0 - 1.0))));
		boids[i].addForce(vector((1.0 + rand() / (RAND_MAX / (-1.0 - 1.0))), (1.0 + rand() / (RAND_MAX / (-1.0 - 1.0))), 0));
	}
}
