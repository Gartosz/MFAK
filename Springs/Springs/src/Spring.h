#pragma once
#include "ofMain.h"

class Spring
{
public:
	std::pair<ofPoint, ofPoint> coordinates;
	std::pair<ofPoint, ofPoint> prev_coordinates;
	Spring() {}
	Spring(ofPoint pos1, ofPoint pos2)
	{
		coordinates = std::pair<ofPoint, ofPoint>(pos1, pos2);
		prev_coordinates = std::pair<ofPoint, ofPoint>(pos1, pos2);
	}
	
};

