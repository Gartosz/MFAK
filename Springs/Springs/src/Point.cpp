#include "Point.h"

void Point::update(const ofVec3f& gravity, const float& dt)
{
	force += gravity;
	ofVec3f tmp = prev_pos;
	prev_pos = pos;
	pos = 2 * pos - tmp + (force / mass) * dt * dt;
	velocity = pos - prev_pos;
}