#pragma once
#include "ofMain.h"

class SpringsSystem
{
public:
	std::vector<std::vector<float>> coordinates;

	SpringsSystem() {}
	SpringsSystem(std::vector<std::vector<float>> const &positions)
	{
		coordinates = positions;
	}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length)
	{
		for (int y = 0; y < y_count; ++y)
		{
			coordinates.emplace_back();
			coordinates[y].emplace_back(y * y_length);
			coordinates[y].emplace_back(0);
			for (int x = 0; x < x_count; ++x)
				coordinates[y].emplace_back(x * x_length);
		}
	}
};
