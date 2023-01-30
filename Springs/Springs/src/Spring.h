#pragma once
#include "ofMain.h"
#include "Point.h"

class Spring
{
public:
	std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>> vertexes;
	Spring() {}
	Spring(std::shared_ptr<Point> point1, std::shared_ptr<Point> point2)
	{
		vertexes = std::pair <std::shared_ptr<Point>, std::shared_ptr<Point>>(point1, point2);
	}
	
};

