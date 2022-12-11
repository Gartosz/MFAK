#include "ParticleSystem.h"

void ParticleSystem::generate()
{
	for (int i = 0; i < max_particles; i++)
		particles.push_back(particles_parameters());
}

void ParticleSystem::wake(size_t index)
{
    if (last_alive_index < max_particles)
    {
        particles[index].is_alive = true;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.begin() + index + 2);
        last_alive_index++;
    }

}

void ParticleSystem::kill(size_t index)
{
    if (last_alive_index > -1)
    {
        particles[index].is_alive = false;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.end());
        --last_alive_index;
    }

}
