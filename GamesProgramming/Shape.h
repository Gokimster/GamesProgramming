#pragma once
#include "vector.h"

class Shape
{
	public:
		vector pos;
		vector velocity;
		vector acceleration;

		Shape(vector position);
		void addForce();

};
