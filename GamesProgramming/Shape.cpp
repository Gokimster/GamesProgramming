#include "Shape.h"

Shape::Shape(vector pos)
{
	this->pos = vector(pos);
	acceleration = vector();
	velocity = vector();
}