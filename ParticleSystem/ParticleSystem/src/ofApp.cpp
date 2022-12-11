#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.setSize(250, 120);
	gui.add(delta_time.setup("Speed", 1.00, 0.00, 2.00));
	gui.add(gravity.setup("Gravity", 9.81, 0.0, 20.0));
	gui.add(viscosity.setup("Viscosity", 0.000181, 0.0, 0.01));
	gui.add(apply_viscosity.setup("Toggle drag force", false, 20, 20));
}

void ofApp::update() {
		
}

void ofApp::drawParticles()
{
	for (auto& disk : system.disks)
	{
		ofSetColor(disk.color);
		ofDrawSphere(disk.pos, disk.size);
	}
}

void ofApp::draw() {
	camera.begin();
	//ofEnableDepthTest();
	drawParticles();
	//ofDisableDepthTest();
	camera.end();
}