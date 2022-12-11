#pragma once

#include "ofMain.h"
#include <vector>
#include <ctime>
#include <stdio.h>
#include "ofXGui.h"
#include "../ParticleSystem.h"

class ofApp : public ofBaseApp{

	public:
		ofApp(int n = 1000, float epsilon = 2.0)
		{
			ofSetCircleResolution(100);
			system = ParticleSystem(n);
		}

	private:
		ParticleSystem system;
		int number;
		ofEasyCam camera;
		ofxPanel gui;

		ofxFloatSlider delta_time;
		ofxFloatSlider gravity;
		ofxFloatSlider attractor_mass;
		ofxFloatSlider viscosity;
		ofxToggle apply_viscosity;


		void setup();
		void update();
		void draw();

		void drawParticles();
};
