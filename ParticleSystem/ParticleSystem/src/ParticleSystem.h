#pragma once
#include "ofMain.h"
#include <vector>
#include <memory>

class ParticleData
{
public:
	ParticleData() {}
	ParticleData(int max_n) 
	{
		max_particles = max_n;
		generate();
	}

	size_t max_particles = 0;
	size_t last_alive_id = 0;

	struct particles_parameters
	{
		int size = 1;
		glm::vec4 pos = glm::vec4(0.0f);
		ofColor color = { 255, 255, 255 };
		std::shared_ptr<std::vector<glm::vec2>> velocity_range;
		glm::vec4 velocity = glm::vec4(0.0f);
		float gravity = 0;
		bool is_alive = false;
		float time_to_live = 0;

		particles_parameters()
		{
			size = std::rand() % 2 + 1;
			velocity_range = std::make_shared<std::vector<glm::vec2>>();
		}
	};

	std::vector<particles_parameters> particles;
	void kill(size_t index);
	void wake(size_t index, size_t alive_time, float gravity, glm::vec4 velocity);

private:
	void generate();
};

class ParticleGenerator
{
public:
	ofColor color;
	ParticleGenerator() {
		color = ofColor::white;
	}
	virtual ~ParticleGenerator() { }

	virtual void generate(double dt, ParticleData* p, size_t start_index, size_t end_index) = 0;
};

class ParticleEmitter
{
protected:
	std::vector<std::shared_ptr<ParticleGenerator>> generators;

public:
	int emit_rate;
	size_t alive_time;
	float gravity;
	glm::vec4 init_velocity_range[2] = { glm::vec4(0.0), glm::vec4(0.0) };
	ParticleEmitter(const int &rate, const size_t &alive_time_, const float &_gravity = 0)
	{
		emit_rate = rate;
		alive_time = alive_time_;
		gravity = _gravity;
	}

	void emit(double dt, ParticleData* p);
	void addGenerator(std::shared_ptr<ParticleGenerator> gen) { generators.push_back(gen); }

};

class ParticleSystem
{
protected:
	std::vector<std::shared_ptr<ParticleEmitter>> emitters;

public:
	ParticleData data;
	float floor_level;
	ParticleSystem(int max_n = 10000, float _floor = 0)
	{
		data = ParticleData(max_n);
		floor_level = _floor;
	}
	void addEmitter(std::shared_ptr<ParticleEmitter> em) { emitters.push_back(em); }
	void update(double dt);
	static float linearRand(glm::vec2 values_range);
};