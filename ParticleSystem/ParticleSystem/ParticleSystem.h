#pragma once
#include "ofMain.h"
#include <vector>

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
	size_t last_alive_index = -1;

	struct particles_parameters
	{
		int size = 1;
		glm::vec4 pos = { 0, 0, 0, 0 };
		ofColor color = { 255, 255, 255 };
		float mass = 0;
		glm::vec4 velocity = { 0, 0, 0, 0 };
		glm::vec4 acceleration = { 0, 0, 0, 0 };
		bool is_alive = false;
		float time_to_live = 0;

		particles_parameters()
		{
			size = std::rand() % 3 + 1;
			mass = ofRandom(20.0, 80.0);
		}
	};

	std::vector<particles_parameters> particles;
	void kill(size_t index);
	void wake(size_t index);

private:
	void generate();
};

class ParticleGenerator
{
public:
	ParticleGenerator() { }
	virtual ~ParticleGenerator() { }

	virtual void generate(double dt, ParticleData* p, size_t start_index, size_t end_index) = 0;
};

class ParticleEmitter
{
protected:
	std::vector<std::shared_ptr<ParticleGenerator>> generators;

public:
	int emit_rate;
	ParticleEmitter(int rate = 0)
	{
		emit_rate = rate;
	}

	void addGenerator(std::shared_ptr<ParticleGenerator> gen) { generators.push_back(gen); }

};

class ParticleSystem
{
protected:
	
public:
	ParticleData data;
	ParticleSystem(int max_n = 10000)
	{
		data = ParticleData(max_n);
	}
};