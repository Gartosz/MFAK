#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.setSize(250, 120);
	gui.add(delta_time.setup("Speed", 1.00, 0.00, 2.00));
	gui.add(gravity.setup("Gravity", 9.81, 0.0, 20.0));
	gui.add(attractor_mass.setup("Mass", 10.0, 0.0, 300.0));
	gui.add(viscosity.setup("Viscosity", 0.000181, 0.0, 0.001));
	gui.add(apply_attractor.setup("Toggle attractor force", false, 20, 20));
	gui.add(apply_viscosity.setup("Toggle drag force", false, 20, 20));
}

//--------------------------------------------------------------
void ofApp::update() {
	float windowSize[2] = { ofGetWidth(), ofGetHeight() };
	for (auto& disk : disks)
	{
		ofVec2f acceleration(0, 0);
		if (apply_viscosity)
	{
			ofVec2f drag_force = -6 * PI * disk.velocity * viscosity * disk.size;
			acceleration += drag_force / disk.mass;
		}
		if (apply_attractor)
		{
		for (auto& force_point : force_points) 
		{
			float distance = force_point.distance(disk.pos);
			ofVec2f distance_vector(force_point - disk.pos);
				ofVec2f force = (gravity * attractor_mass * disk.mass * distance_vector) / pow(distance * distance + epsilon, 3 / 2);
				acceleration += force / disk.mass;
		}
		}
		disk.velocity += acceleration * delta_time;
		disk.pos += disk.velocity * delta_time;
		checkWallHit(disk, windowSize);
	}
}

void ofApp::checkWallHit(disk_parameters& parameter, float const* windowSize)
{
	for (int i = 0; i < 2; ++i)
	{
		if (parameter.pos[i] >= windowSize[i] - parameter.size)
		{
			parameter.pos[i] = windowSize[i] - parameter.size;
			parameter.velocity[i] *= -0.8;
		}
		else if (parameter.pos[i] <= parameter.size)
		{
			parameter.pos[i] = parameter.size;
			parameter.velocity[i] *= -0.8;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (auto& disk : disks)
	{
		ofSetColor(disk.color);
		ofDrawCircle(disk.pos, disk.size);
	}
	for (auto& force_point : force_points)
	{
		ofSetColor(ofColor::black);
		ofDrawCircle(force_point, force_point_size+3);
	ofSetColor(force_point_color);
	for (auto& force_point : force_points)
		ofDrawCircle(force_point, force_point_size);
	}
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	force_points.push_back(ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
