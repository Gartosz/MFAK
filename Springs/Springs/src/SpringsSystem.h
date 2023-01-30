#pragma once
#include "ofMain.h"
#include "Point.h"

class SpringsSystem
{
public:
	std::vector<std::vector<Point>> spring_points;
	int size = 0;
	float k = 0;
	SpringsSystem() {}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length, const int &_size = 3, float _k = 0.5)
	{
		generatePoints(y_count, x_count, x_length, y_length);
		size = _size;
		k = _k;
	}
private:
	void generatePoints(const int& y_count, const int& x_count, const int& x_length, const int& y_length);
};
