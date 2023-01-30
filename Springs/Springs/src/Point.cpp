#include "Point.h"

void Point::update(const ofVec3f& gravity, const float& dt)
{
	force += gravity;
	pos = 2 * pos - prev_pos + (force / mass) * dt * dt;
}