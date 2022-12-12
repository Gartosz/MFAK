#include "ParticleSystem.h"

void ParticleData::generate()
{
	for (int i = 0; i < max_particles; i++)
		particles.push_back(particles_parameters());
}

void ParticleData::wake(size_t index)
{
    if (last_alive_index < max_particles)
    {
        particles[index].is_alive = true;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.begin() + index + 2);
        ++last_alive_index;
    }

}

void ParticleData::kill(size_t index)
{
    if (last_alive_index > -1)
    {
        particles[index].is_alive = false;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.end());
        --last_alive_index;
    }

}
