#pragma once
#include "ofMain.h"

class Spring
{
public:
	glm::vec2 velocity;
	ofPoint pos;
	float mass;
	Spring(ofPoint _pos, float _mass = 10)
	{
		velocity = glm::vec2{ 0.0 };
		pos = _pos;
		mass = _mass;
	}
};
