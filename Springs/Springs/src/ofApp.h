#pragma once

#include "ofMain.h"
#include "SpringsSystem.h"
#include "ofXGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

private:
	ofEasyCam camera;
	SpringsSystem system{ 50, 70, 2, 2 };
	ofxPanel gui;
};
