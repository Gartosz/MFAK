#pragma once
#include "ofMain.h"
#include "Point.h"
#include "Spring.h"

class SpringsSystem
{
public:
	std::vector<std::vector<Point>> spring_points;
	std::vector<Spring> springs;
	int size = 0;
	float k = 0;
	SpringsSystem() {}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length, const int &_size = 3, float _k = 0.5)
	{
		generatePoints(y_count, x_count, x_length, y_length);
		generateSprings();
		size = _size;
		k = _k;
	}
	void draw();
	void drawCircles();
	void drawLines();
private:
	void generatePoints(const int& y_count, const int& x_count, const int& x_length, const int& y_length);
	void generateSprings();
};
