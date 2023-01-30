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
	for (int y = 0; y < spring_points.size(); ++y)
	{
		for (int x = 0; x < spring_points[y].size()/2; ++x)
		{
			springs.emplace_back( spring_points[y][x * 2].pos, spring_points[y][x * 2 + 1].pos);
			if (x * 2 + 2 < spring_points[y].size())
				springs.emplace_back(spring_points[y][x * 2 + 1].pos, spring_points[y][x * 2 + 2].pos);
			if (y + 1 < spring_points.size())
			{
				springs.emplace_back(spring_points[y][x * 2].pos, spring_points[y + 1][x * 2].pos);
				springs.emplace_back(spring_points[y][x * 2 + 1].pos, spring_points[y + 1][x * 2 + 1].pos);
				if (x * 2 + 3 >= spring_points[y].size())
					springs.emplace_back(spring_points[y][x * 2 + 2].pos, spring_points[y + 1][x * 2 + 2].pos);
			}
		}
	}
}

void SpringsSystem::draw()
{
	drawCircles();
	drawLines();
}

void SpringsSystem::drawCircles()
{
	for (int y = 0; y < spring_points.size(); ++y)
	{
		for (int x = 0; x < spring_points[y].size(); ++x)
		{
			ofDrawCircle(spring_points[y][x].pos, size);
		}
	}
}

void SpringsSystem::drawLines()
{
	for (auto& spring : springs)
		ofDrawLine(spring.coordinates.first, spring.coordinates.second);
}
