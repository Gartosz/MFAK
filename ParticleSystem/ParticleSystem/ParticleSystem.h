#pragma once
#include "ofMain.h"

class ParticleSystem
{
public:
	struct disk_parameters
	{
		int size = 1;
		ofVec3f pos = { 0, 0, 0 };
		ofColor color = { 255, 255, 255 };
		float mass = 0;
		ofVec3f velocity = { 1, 1, 1 };

		disk_parameters()
		{
			size = std::rand() % 3 + 1;
			mass = ofRandom(20.0, 80.0);
			velocity[0] = ofRandom(-5.0, 5.0);
			velocity[1] = ofRandom(-5.0, 5.0);
			velocity[2] = ofRandom(-5.0, 5.0);
		}
	};

	std::vector<disk_parameters> disks;

	ParticleSystem(int max_n = 10000, float epsilon = 5)
	{
		max_particles = max_n;
		for (int i = 0; i < max_particles; i++)
		{
			disks.push_back(disk_parameters());
		}
		this->epsilon = epsilon;
	}
private:
	float epsilon;
	int max_particles = 0;
};