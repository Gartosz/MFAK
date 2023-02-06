#pragma once
#include "ofMain.h"

class Point
{
public:
	ofVec3f velocity;
	ofVec3f force;
	ofPoint pos;
	ofPoint prev_pos;
	float mass = 0;
	Point() {}
	Point(ofPoint _pos, float _mass = 30)
		: pos(_pos), prev_pos(_pos), mass(_mass) {}
	void update(const float &gravity, const glm::vec3& wind, const float &dt);
};
