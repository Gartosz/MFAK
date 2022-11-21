#pragma once

#include "ofMain.h"
#include <vector>
#include <ctime>
#include <stdio.h>
#include "ofXGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxPanel gui;

		ofxFloatSlider speed_slider;

		ofApp(int n = 1000)
		{
			ofSetCircleResolution(100);
			number = n;
			for (int i = 0; i < n; i++)
			{
				parameters.push_back(disk_parameters());
			}
		}

	private:
		int number;
		struct disk_parameters
		{
			int size = 1;
			ofVec2f pos = { 0, 0 };
			ofColor color = { 0, 0, 0 };
			int mass = 0;
			ofVec2f velocity =  { 1, 1 };
			ofVec2f acceleration = { 1, 1 };

			disk_parameters()
			{
				size = std::rand() % 20 + 5;
				pos[0] = std::rand() % (ofGetWidth() - size * 2);
				pos[1] = std::rand() % (ofGetHeight() - size * 2);
				color[0] = ofRandom(0, 255);
				color[1] = ofRandom(0, 255);
				color[2] = ofRandom(0, 255);
				mass = ofRandom(0.1, 5.0);
				velocity[0] = ofRandom(-3.0, 3.0);
				velocity[1] = ofRandom(-3.0, 3.0);
			}
		};
		std::vector<disk_parameters> parameters;

		bool exceedsBorder(float const& position, float const& size, float const& borderSize);
		void changeDirection(disk_parameters& parameter, float const* windowSize);
};
