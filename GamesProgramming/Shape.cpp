#include "stdafx.h"
#include "Shape.h"

Shape::Shape(vector pos, float mass)
{
	this->pos = vector(pos);
	this->mass = mass;
	acceleration = vector();
	velocity = vector();
}

void Shape::updatePosition(int dt)
{
	//gravity
	velocity = velocity + (vector(0, -0.98, 0)) * ((float)dt / 1000);
	pos = pos + velocity;
}