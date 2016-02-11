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
	vector align = alignment(neighbourhood, nSize);
	vector cohes = cohesion(neighbourhood, nSize);
	vector sep = separation(neighbourhood, nSize);
	velocity.x += align.x + cohes.x + sep.x;
	velocity.y += align.y + cohes.y + sep.y;
	velocity.z = 0;

	velocity = velocity.normal();
	velocity = velocity * speed;
	pos = pos + velocity * (dt / 1000);
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
