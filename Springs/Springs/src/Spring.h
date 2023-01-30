#pragma once
#include "ofMain.h"

class Spring
{
public:
	std::pair<ofPoint, ofPoint> coordinates;
	Spring() {}
	Spring(ofPoint pos1, ofPoint pos2)
	{
		coordinates = std::pair<ofPoint, ofPoint>(pos1, pos2);
	}
};

