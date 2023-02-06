#include "Point.h"

void Point::update(const float& gravity, const glm::vec3 &wind, const float& dt)
{
	force.y += gravity;
	force += ofVec3f{wind}.getNormalized();
	ofVec3f tmp = prev_pos;
	prev_pos = pos;
	pos = 2 * pos - tmp + (force / mass) * dt * dt;
	velocity = (pos - prev_pos) / dt;
	force = ofVec3f{ 0.0f };
}