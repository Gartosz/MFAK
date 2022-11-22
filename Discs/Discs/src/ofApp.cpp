#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(speed_slider.setup("Modify speed", 1.00, 0.00, 2.00));
	gui.add(gravity_slider.setup("Modify gravity", 0.0, 0.0, 20.0));
	gui.add(mass_slider.setup("Modify mass", 0.0, 0.0, 500.0));
	gui.add(viscosity.setup("Modify viscosity", 0.0, 0.000181, 0.001));
}

//--------------------------------------------------------------
void ofApp::update() {
	float windowSize[2] = { ofGetWidth(), ofGetHeight() };
	for (auto& disk : parameters)
	{
		disk.pos += disk.velocity * speed_slider;
		disk.velocity += disk.acceleration * speed_slider;
		wallHit(disk, windowSize);
		for (auto& force_point : force_points) 
		{
			float distance = force_point.distance(disk.pos);
			ofVec2f distance_vector(force_point - disk.pos);
			ofVec2f force = (gravity_slider * mass_slider * disk.mass * distance_vector) / pow(distance, 3);
			disk.acceleration += force / disk.mass;
		}
		ofVec2f drag_force = -6*PI*disk.velocity*viscosity*disk.size;
		disk.acceleration += drag_force;
	}
}

void ofApp::wallHit(disk_parameters& parameter, float const* windowSize)
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
	for (int i = 0; i < number; ++i)
	{
		ofSetColor(parameters[i].color);
		ofDrawCircle(parameters[i].pos, parameters[i].size);
	}
	ofSetColor(force_point_color);
	for (auto& force_point : force_points)
		ofDrawCircle(force_point, force_point_size);
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
