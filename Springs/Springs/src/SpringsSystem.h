#pragma once
#include "ofMain.h"
#include "Point.h"
#include "Spring.h"

class SpringsSystem
{
public:
	std::vector<std::vector<std::shared_ptr<Point>>> spring_points;
	std::vector<Spring> springs;
	int size = 0;
	float ks = 0;
	float kd = 0;
	float dt = 0;
	const ofVec3f g = ofVec3f(0, - 9.81, 0);
	SpringsSystem() {}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length, const int &_size = 3, float _ks = 100, float _kd = 25, float _dt = 1)
	{
		generatePoints(y_count, x_count, x_length, y_length);
		generateSprings();
		size = _size;
		ks = _ks;
		kd = _kd;
		dt = _dt;
	}
	void draw();
	void drawCircles();
	void drawLines();
private:
	void generatePoints(const int& y_count, const int& x_count, const int& x_length, const int& y_length);
	void generateSprings();
};
