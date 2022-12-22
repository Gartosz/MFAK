#pragma once

#include "ofMain.h"
#include <vector>
#include <ctime>
#include <stdio.h>
#include "../ParticleSystem.h"
#include "../ParticleGenerators.h"

class ofApp : public ofBaseApp{

	public:
		ofApp(int n = 1000, int _dt = 5, float _floor = 0)
		{
			dt = _dt;
			floor_level = _floor;
			ofSetCircleResolution(100);
			system = ParticleSystem(n, floor_level);
			createEmitters();
		}

	private:
		ParticleSystem system;
		int number;
		int dt;
		float floor_level;
		ofEasyCam camera;

		void update();
		void draw();
		void drawParticles();
		void createEmitters();
};
