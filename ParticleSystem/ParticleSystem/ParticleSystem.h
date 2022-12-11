#pragma once
#include "ofMain.h"

class ParticleSystem
{
public:
	size_t max_particles = 0;
	size_t last_alive_index = 0;

	struct disk_parameters
	{
		int size = 1;
		glm::vec4 pos = { 0, 0, 0, 0 };
		ofColor color = { 255, 255, 255 };
		float mass = 0;
		glm::vec4 velocity = { 1, 1, 1, 1 };
		glm::vec4 acceleration = { 0, 0, 0, 0 };
		bool is_alive = false;
		float time_to_live = 0;

		disk_parameters()
		{
			size = std::rand() % 3 + 1;
			mass = ofRandom(20.0, 80.0);
		}
	};

	std::vector<disk_parameters> particles;

	ParticleSystem(int max_n = 10000)
	{
		max_particles = max_n;
		for (int i = 0; i < max_particles; i++)
		{
			particles.push_back(disk_parameters());
		}

	}
	void generate(size_t maxSize);
	void kill(size_t index);
	void wake(size_t index);

};