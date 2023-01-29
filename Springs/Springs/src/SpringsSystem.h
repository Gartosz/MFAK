#pragma once
#include "ofMain.h"

class SpringsSystem
{
public:
	std::vector<std::vector<ofPoint>> coordinates;

	SpringsSystem() {}
	SpringsSystem(std::vector<std::vector<ofPoint>> const &positions)
	{
		coordinates = positions;
	}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length)
	{
		for (int y = 0; y < y_count; ++y)
		{
			coordinates.emplace_back(ofPoint(y * y_length, y * y_length + y_length));
			for (int x = 0; x < x_count; ++x)
				coordinates[y].emplace_back(ofPoint(x * x_length, x * x_length + x_length));
		}
	}
};
