#pragma once
#include "ofMain.h"

class Point
{
public:
	glm::vec2 velocity;
	ofPoint pos;
	ofPoint prev_pos;
	float mass = 0;
	Point() {}
	Point(ofPoint _pos, float _mass = 30)
		: pos(_pos), prev_pos(_pos), mass(_mass) {}

};
