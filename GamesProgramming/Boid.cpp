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
	if (nSize > 1)
	{
		vector align = alignment(neighbourhood, nSize);
		vector cohes = cohesion(neighbourhood, nSize);
		vector sep = separation(neighbourhood, nSize);
		velocity.x += align.x * 0.6 + cohes.x * 0.7 + sep.x * 0.2;
		velocity.y += align.y * 0.6 + cohes.y * 0.7 + sep.y * 0.2;
		velocity.z = 0;
	}

	velocity = velocity.normal();
	velocity = velocity * speed;
	pos = pos + (velocity * ((float)dt / 1000));
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
	return v;
}
