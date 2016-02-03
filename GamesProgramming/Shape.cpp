#include "stdafx.h"
#include "Shape.h"

Shape::Shape(vector pos, float mass)
{
	this->pos = vector(pos);
	this->mass = mass;
	acceleration = vector();
	velocity = vector();
}

Shape::Shape()
{

}

void Shape::updatePosition(int dt)
{
	//gravity
	velocity = velocity + (vector(0, -15, 0)) * ((float)dt / 1000);
	addVerticalFriction(dt);
	pos = pos + velocity*((float)dt / 1000);
}

void Shape::addForce(vector f)
{
	velocity = f + velocity;
}

void Shape::addVerticalFriction(int dt)
{
	if (velocity.y > 0)
	{
		velocity.y -= 0.05 * ((float)dt / 1000);
	}else {
		velocity.y += 0.05 * ((float)dt / 1000);
	}
}
