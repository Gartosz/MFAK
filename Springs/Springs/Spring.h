#pragma once
#include "ofMain.h"

class Spring
{
public:
	ofPoint coordinates[2];
	float length;

	Spring(ofPoint *coordinates)
	{
		this->coordinates[0] = coordinates[0];
		this->coordinates[1] = coordinates[1];
		length = coordinates[0].distance(coordinates[1]);
	}

};

