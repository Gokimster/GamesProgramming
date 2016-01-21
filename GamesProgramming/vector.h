#pragma once
class vector {
	public:
		//variables
		float x;
		float y;
		float z;

		//constructors
		vector();
		vector(vector v);
		vector(float, float, float);

		float length();
		vector normal();
		void copy(vector v);

		//scalar operations
		vector operator+(float scalar);
		vector operator-(float scalar);
		vector operator*(float scalar);
		vector operator/(float scalar);

		//vector operations
		bool operator==(vector v2);
		vector operator+(vector v2);
		vector operator-(vector v2);
		vector operator*(vector v2);
		vector operator/(vector v2);

		vector cross(vector v2);
		float dot(vector v2);
};
