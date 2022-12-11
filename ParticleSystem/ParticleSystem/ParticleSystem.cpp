#include "ParticleSystem.h"

void ParticleSystem::generate()
{
	for (int i = 0; i < max_particles; i++)
		particles.push_back(disk_parameters());
}

void ParticleSystem::wake(size_t index)
{

}

void ParticleSystem::kill(size_t index)
{

}
