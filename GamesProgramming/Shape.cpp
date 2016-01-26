#include "stdafx.h"
#include "Shape.h"

Shape::Shape(vector pos, float mass)
{
	this->pos = vector(pos);
	this->mass = mass;
	acceleration = vector();
	velocity = vector();
}