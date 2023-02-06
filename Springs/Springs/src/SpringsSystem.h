#pragma once
#include "ofMain.h"
#include "Point.h"
#include "Spring.h"
#include "ofxGui.h"

class SpringsSystem
{
public:
	std::vector<std::vector<std::shared_ptr<Point>>> spring_points;
	std::vector<Spring> springs;
	int size = 0;
	ofxFloatSlider ks = 0;
	ofxFloatSlider kd = 0;
	ofxFloatSlider dt = 1;
	ofxFloatSlider g = -1;
	ofxVec3Slider wind;
	SpringsSystem() {}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length, const int& _size = 1)
	{
		generatePoints(y_count, x_count, x_length, y_length);
		generateSprings();
		size = _size;
	}
	void draw();
	void drawCircles();
	void drawLines();
	void update();
private:
	void generatePoints(const int& y_count, const int& x_count, const int& x_length, const int& y_length);
	void generateSprings();
};
