#include "stdafx.h"
#include "Boid.h"

Boid::Boid(vector position, float speed)
{
	this->pos = position;
	this->speed = speed;
}

Boid::Boid()
{
}

void Boid::update(int dt, Boid neighbourhood[], int nSize)
{
	if (nSize > 0)
	{
		vector align = alignment(neighbourhood, nSize);
		vector cohes = cohesion(neighbourhood, nSize);
		vector sep = separation(neighbourhood, nSize);
		velocity.x += align.x   * 1.0+ cohes.x * 1 + sep.x * 1.2;
		velocity.y += align.y * 1.0 + cohes.y * 1.0 + sep.y * 1.2;
		velocity.z = 0;
	}

	velocity = velocity.normal();
	pos = pos + (velocity * ((float)dt / 1000) * speed);
}

vector Boid::alignment(Boid neighbourhood[], int nSize)
{
	vector v;
	for (int i = 0; i < nSize; i++)
	{
		v.x += neighbourhood[i].velocity.x;
		v.y += neighbourhood[i].velocity.y;
	}
	v.x /= nSize;
	v.y /= nSize;
	v = v.normal();
	return v;
}

vector Boid::cohesion(Boid neighbourhood[], int nSize)
{

	vector v;
	for (int i = 0; i < nSize; i++)
	{
		v.x += neighbourhood[i].pos.x;
		v.y += neighbourhood[i].pos.y;
	}
	v.x /= nSize;
	v.y /= nSize;
	v.x = v.x - pos.x;
	v.y = v.y - pos.y;
	v = v.normal();
	return v;
}

vector Boid::separation(Boid neighbourhood[], int nSize)
{
	vector v;
	for (int i = 0; i < nSize; i++)
	{
		v.x += neighbourhood[i].pos.x - pos.x;
		v.y += neighbourhood[i].pos.y - pos.y;
	}
	v.x /= nSize;
	v.y /= nSize;
	v.x = -(v.x - pos.x);
	v.y = -(v.y - pos.y);
	v = v.normal();
	return v;
}
