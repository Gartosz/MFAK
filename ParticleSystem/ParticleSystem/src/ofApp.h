#pragma once

#include "ofMain.h"
#include <vector>
#include <ctime>
#include <stdio.h>
#include "ofXGui.h"

class ofApp : public ofBaseApp{

	public:
		ofApp(int n = 1000, float epsilon = 2.0)
		{
			ofSetCircleResolution(100);
			number = n;
			for (int i = 0; i < n; i++)
			{
				disks.push_back(disk_parameters());
			}
			this->epsilon = epsilon;
		}

	private:
		int number;
		ofEasyCam camera;
		struct disk_parameters
		{
			int size = 1;
			ofVec3f pos = { 0, 0, 0 };
			ofColor color = { 255, 255, 255 };
			float mass = 0;
			ofVec3f velocity =  { 1, 1, 1 };

			disk_parameters()
			{
				size = std::rand() % 3 + 1;
				pos[0] = std::rand() % (ofGetWidth() - size * 2);
				pos[1] = std::rand() % (ofGetHeight() - size * 2);
				pos[2] = std::rand() % 2000;
				mass = ofRandom(20.0, 80.0);
				velocity[0] = ofRandom(-5.0, 5.0);
				velocity[1] = ofRandom(-5.0, 5.0);
				velocity[2] = ofRandom(-5.0, 5.0);
			}
		};
		ofxPanel gui;

		ofxFloatSlider delta_time;
		ofxFloatSlider gravity;
		ofxFloatSlider attractor_mass;
		ofxFloatSlider viscosity;
		ofxToggle apply_viscosity;

		float epsilon;

		std::vector<disk_parameters> disks;
		std::vector<ofVec2f> force_points;


		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);

		float checkValueChange(float const& before_modification, float const& pos);
		void checkWallHit(disk_parameters& parameter, float const* windowSize);
		void drawDisks();
		void applyDragForce(ofApp::disk_parameters const &disk, ofVec2f& acceleration);
		void moveDisk(ofApp::disk_parameters& disk, ofVec2f const& acceleration, float const* windowSize);
};
