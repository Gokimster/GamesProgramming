#pragma once
#include "vector.h"

class Shape
{
	public:
		vector pos;
		vector velocity;
		vector acceleration;
		float mass;

		Shape(vector pos, float mass);
		Shape();
		void addForce(vector f);
		void updatePosition(int dt);
		void addVerticalFriction(int dt);

};
