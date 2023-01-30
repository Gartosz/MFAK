#include "SpringsSystem.h"

void SpringsSystem::generatePoints(const int& y_count, const int& x_count, const int& x_length, const int& y_length)
{
	for (int y = 0; y <= y_count; ++y)
	{
		spring_points.emplace_back();
		for (int x = 0; x <= x_count; ++x)
			spring_points[y].emplace_back(Point(ofPoint(x * x_length, y * y_length)));
	}
}

void SpringsSystem::generateSprings()
{

}
