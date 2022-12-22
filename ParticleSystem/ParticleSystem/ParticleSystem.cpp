#include "ParticleSystem.h"
#include "glm/gtc/random.hpp"

void ParticleData::generate()
{
	for (int i = 0; i < max_particles; i++)
		particles.push_back(particles_parameters());
}

void ParticleData::wake(size_t index, size_t alive_time, float gravity, glm::vec4 velocity)
{
    if (last_alive_id <= max_particles)
    {
        particles[index].is_alive = true;
        particles[index].time_to_live = alive_time;
        particles[index].gravity = gravity;
        particles[index].velocity = velocity;
        std::rotate(particles.begin(), particles.begin() + index, particles.begin() + index + 1);
        ++last_alive_id;
    }

}

void ParticleData::kill(size_t index)
{
    if (last_alive_id > 0)
    {
        particles[index].is_alive = false;
        std::rotate(particles.begin(), particles.begin() + index + 1, particles.begin() + last_alive_id);
        --last_alive_id;
    }

}

void ParticleEmitter::emit(double dt, ParticleData* p)
{
    const size_t maxNewParticles = static_cast<size_t>(dt * emit_rate);
    const size_t start_index = p->last_alive_id;
    const size_t end_index = std::min(start_index + maxNewParticles, p->max_particles - 1);

    for (auto& gen : generators)
        gen->generate(dt, p, start_index, end_index);

    for (size_t i = start_index; i < end_index; ++i)
    {
        glm::vec4 velocity = glm::linearRand(init_velocity_range[0], init_velocity_range[1]);
        p->wake(i, alive_time, gravity, velocity);
    }
}

void ParticleSystem::update(double dt)
{
    for (auto& em : emitters)
    {
        em->emit(dt, &data);
    }
    for (int i = 0; i < data.last_alive_id; ++i)
    {
        data.particles[i].velocity.y -= data.particles[i].gravity * dt;
        data.particles[i].pos += data.particles[i].velocity * dt;
        if ((data.particles[i].time_to_live -= dt) <= 0)
            data.kill(i);
    }
}