#include "stdafx.h"
#include "BoidsManager.h"
#include <random>
#include <time.h>
#include <algorithm>

BoidsManager::BoidsManager(vector pos, float boidSpeed, float nSize)
{
	this->pos = pos;
	this->boidSpeed = boidSpeed;
	this->nSize = nSize;
	initBoids();
}

void BoidsManager::updateBoids(int dt, int posBounds)
{
	int wSize = 9;
	Boid * iterate = new Boid[boids_no];
	for (int i = 0; i < boids_no; i++)
	{
		Boid * neighbours = new Boid[boids_no];
		int j = 0;
		Boid b = boids[i];
		for (int x = 0; x < boids_no; x++)
		{
			if (x == i)
			{
				break;
			}
			bool added = false;
			if (b.pos.distance(boids[x].pos) < nSize)
			{
				neighbours[j++] = boids[x];
				added = true;
			}
			//wrap the neighbourhood around window
			if (!added)
			{
				Boid n = boids[x];
				if (wSize - abs(b.pos.y) < nSize && wSize - abs(b.pos.x) < nSize)
				{
					n.pos.x = n.pos.x + (wSize * n.pos.x / abs(n.pos.x) * -2);
					n.pos.y = n.pos.y + (wSize * n.pos.y / abs(n.pos.y) * -2);
				}
				else {
					if (wSize - abs(b.pos.x) < nSize)
					{
						n.pos.x = n.pos.x + (wSize * n.pos.x / abs(n.pos.x) * -2);
					}
					if (wSize - abs(b.pos.y) < nSize)
					{
						n.pos.y = n.pos.y + (wSize * n.pos.y / abs(n.pos.y) * -2);
					}
				}
				if (b.pos.distance(n.pos) < nSize)
				{
					neighbours[j++] = n;
				}
			}
				
		}
		b.update(dt, neighbours, j);
		if (abs(b.pos.x) > wSize)
		{
			b.pos.x = b.pos.x + 2 * wSize * (b.pos.x) / abs(b.pos.x) * -1;
		}
		if (abs(b.pos.y) > wSize)
		{
			b.pos.y = b.pos.y + 2 * wSize * (b.pos.y) / abs(b.pos.y) * -1;
		}
		iterate[i] = b;
	}
	for (int i = 0; i < boids_no; i++)
	{
		boids[i] = iterate[i];
	}
}

void BoidsManager::initBoids()
{
	srand(time(0));
	for (int i = 0; i < boids_no; i++)
	{
		boids[i] = Boid((pos + (1.0 + rand() / (RAND_MAX / (-1 - 1)))), (boidSpeed + 1.0 + rand() / (RAND_MAX / (-0.2 - 0.2))));
		//boids[i] = Boid(pos, boidSpeed);
		boids[i].addForce(vector((1.0 + rand() / (RAND_MAX / (-1.0 - 1.0))), (1.0 + rand() / (RAND_MAX / (-1.0 - 1.0))), 0));
	}
}
