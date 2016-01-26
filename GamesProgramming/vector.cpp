#include "stdafx.h"
#include "vector.h"
#include <math.h>

//===========================
//Constructors
//===========================
vector::vector() 
{
	x = 0;
	y = 0;
	z = 0;
}

vector::vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float vector::length()
{
	return sqrt(x*x + y*y + z*z);
}

vector vector::normal()
{
	return vector(x / length(), y / length(), z / length());
}

void vector::copy(vector v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

//===========================
//Scalar Operations
//===========================
vector vector::operator+(float scalar)
{
	return vector(x + scalar, y + scalar, z + scalar);
}

vector vector::operator-(float scalar)
{
	return vector(x - scalar, y - scalar, z - scalar);
}

vector vector::operator/(float scalar)
{
	return vector(x / scalar, y / scalar, z / scalar);
}

vector vector::operator*(float scalar)
{
	return vector(x * scalar, y * scalar, z * scalar);
}


//===========================
//Vector Operations
//===========================
bool vector::operator==(vector v2)
{
	return ((x == v2.x) && (y == v2.y) && (z == v2.z));
}

vector vector::operator+(vector v2)
{
	return vector(x + v2.x, y + v2.y, z + v2.z);
}

vector vector::operator-(vector v2)
{
	return vector(x - v2.x, y - v2.y, z - v2.z);
}

float vector::dot(vector v2)
{
	return (x * v2.x +	y * v2.y +	z * v2.z);
}

vector vector::cross(vector v2)
{
	return vector(y * v2.z - z * v2.y, z * v2.x - x * v2.z, x * v2.y - y * v2.x);
}




