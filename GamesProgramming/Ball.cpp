#include "stdafx.h"
#include "Ball.h"

Ball::Ball(vector position, float mass, float radius) :Shape(position, mass) {
	this->radius = radius;
}