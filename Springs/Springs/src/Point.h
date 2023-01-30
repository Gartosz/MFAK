#pragma once
#include "ofMain.h"

class Point
{
public:
	glm::vec2 velocity;
	ofPoint pos;
	float mass;
	Point() {}
	Point(ofPoint _pos, float _mass = 10)
	{
		velocity = glm::vec2{ 0.0 };
		pos = _pos;
		mass = _mass;
	}
};
