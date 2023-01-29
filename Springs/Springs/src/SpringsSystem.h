#pragma once
#include "ofMain.h"

class SpringsSystem
{
public:
	std::vector<std::vector<float>> coordinates;
	int size = 0;
	float k = 0;
	SpringsSystem() {}
	SpringsSystem(std::vector<std::vector<float>> const &positions, const int &_size = 3, float _k = 0.5)
	{
		coordinates = positions;
		size = _size;
		k = _k;
	}
	SpringsSystem(const int &x_count, const int &y_count, const int &x_length, const int y_length, const int &_size = 3, , float _k = 0.5)
	{
		for (int y = 0; y <= y_count; ++y)
		{
			coordinates.emplace_back();
			coordinates[y].emplace_back(y * y_length);
			for (int x = 0; x <= x_count; ++x)
				coordinates[y].emplace_back(x * x_length);
		}
		size = _size;
		k = _k;
	}
};
