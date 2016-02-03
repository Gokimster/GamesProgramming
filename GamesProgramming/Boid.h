#pragma once
#include "Shape.h"

class Boid : public Shape
{
public:
	Boid(vector position);
	Boid();
	void update(int dt);
};