#pragma once
#include "ofMain.h"
#include "Point.h"

class Spring
{
public:
	std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>> vertices;
	float length = 0;
	Spring() {}
	Spring(std::shared_ptr<Point> point1, std::shared_ptr<Point> point2)
		: vertices(std::pair <std::shared_ptr<Point>, std::shared_ptr<Point>>(point1, point2)) 
	{
		length = vertices.first->pos.distance(vertices.second->pos);
	}
	void update(float ks, float kd);

private:
	void Spring::calculateRestoringForce(float ks, float kd);
	
};

