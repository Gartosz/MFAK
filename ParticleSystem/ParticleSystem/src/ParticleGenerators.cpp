#include "ParticleGenerators.h"

void BoxPosGen::generate(double dt, ParticleData* p, size_t start_index, size_t end_index)
{
    glm::vec4 pos_min{ pos.x - max_start_offset.x,
                      pos.y - max_start_offset.y,
                      pos.z - max_start_offset.z,
                      1.0 };
    glm::vec4 pos_max{ pos.x + max_start_offset.x,
                      pos.y + max_start_offset.y,
                      pos.z + max_start_offset.z,
                      1.0 };

    for (size_t i = start_index; i < end_index; ++i)
    {
        p->particles[i].pos = glm::linearRand(pos_min, pos_max);
        p->particles[i].color = color;
    }
}

void VelocityRangeGen::generate(double dt, ParticleData* p, size_t start_index, size_t end_index)
{
    for (size_t i = start_index; i < end_index; ++i)
    {
        p->particles[i].velocity_range = velocity_range;
    }
}
