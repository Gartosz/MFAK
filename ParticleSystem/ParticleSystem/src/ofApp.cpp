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

void ofApp::applyDragForce(ofApp::disk_parameters const &disk, ofVec2f& acceleration)
{
	ofVec2f drag_force = -6 * PI * disk.velocity * viscosity * disk.size;
	acceleration += drag_force / disk.mass;
}

void ofApp::moveDisk(ofApp::disk_parameters& disk, ofVec2f const &acceleration, float const *windowSize)
{
	disk.velocity += acceleration * delta_time;
	disk.pos += disk.velocity * delta_time;
	//checkWallHit(disk, windowSize);
}

void ofApp::update() {
	const float windowSize[2] = { ofGetWidth(), ofGetHeight() };
	for (auto& disk : disks)
	{
		ofVec2f acceleration(0, 0);
		if (apply_viscosity)
			applyDragForce(disk, acceleration);
		moveDisk(disk, acceleration, windowSize);
	}
}

float ofApp::checkValueChange(float const &before_modification, float const& pos)
{
	return before_modification == pos ? 1.0 : -1.0;
}

void ofApp::checkWallHit(disk_parameters& parameter, float const* windowSize)
{
	ofVec2f before_modification(parameter.pos);
	for (int i = 0; i < 2; ++i)
	{
		parameter.pos[i] = ofClamp(parameter.pos[i], parameter.size, windowSize[i] - parameter.size);
		parameter.velocity[i] *= checkValueChange(before_modification[i], parameter.pos[i]);
	}
}

void ofApp::drawDisks()
{
	for (auto& disk : disks)
	{
		ofSetColor(disk.color);
		ofDrawCircle(disk.pos, disk.size);
	}
}

void ofApp::draw() {
	camera.begin();
	//ofEnableDepthTest();
	drawDisks();
	//gui.draw();
	//ofDisableDepthTest();
	camera.end();
}

void ofApp::mousePressed(int x, int y, int button) {
	force_points.push_back(ofVec2f(x, y));
}

