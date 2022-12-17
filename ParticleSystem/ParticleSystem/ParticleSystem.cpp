#include "ParticleSystem.h"

void ParticleData::generate()
{
	for (int i = 0; i < max_particles; i++)
		particles.push_back(particles_parameters());
}

void ParticleData::wake(size_t index)
{
    if (last_alive_index <= max_particles)
    {
        particles[index].is_alive = true;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.begin() + index + 2);
        ++last_alive_index;
    }

}

void ParticleData::kill(size_t index)
{
    if (last_alive_index > 0)
    {
        particles[index].is_alive = false;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.end());
        --last_alive_index;
    }

}

void ParticleEmitter::emit(double dt, ParticleData* p)
{
    const size_t maxNewParticles = static_cast<size_t>(dt * emit_rate);
    const size_t start_index = p->last_alive_index;
    const size_t end_index = std::min(start_index + maxNewParticles, p->max_particles - 1);

    for (auto& gen : generators)            // << gen loop
        gen->generate(dt, p, start_index, end_index);

    for (size_t i = start_index; i < end_index; ++i)  // << wake loop
        p->wake(i);
}

void ParticleSystem::update(double dt)
{
    for (auto& em : emitters)
    {
        em->emit(dt, &data);
    }
}