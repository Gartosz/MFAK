#include "Spring.h"

void Spring::update(float ks, float kd)
{
	calculateRestoringForce(ks, kd);
}


void Spring::calculateRestoringForce(float ks, float kd)
{
	float actual_distance = vertices.first->pos.distance(vertices.second->pos);
	if (actual_distance != 0)
	{
		ofVec3f distance_vector = vertices.first->pos - vertices.second->pos;
		ofVec3f velocity_difference = vertices.first->velocity - vertices.second->velocity;
		ofVec3f force = (actual_distance - length) * ks + velocity_difference * distance_vector * kd / actual_distance;

		vertices.first->force -= force;
		vertices.second->force += force;
	}
}