#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(speed_slider.setup("Modify speed", 1.00, 0.00, 2.00));
	gui.add(gravity_slider.setup("Modify gravity", 0.0, 0.0, 20.0));
	gui.add(mass_slider.setup("Modify mass", 0.0, 0.0, 300.0));
}

//--------------------------------------------------------------
void ofApp::update() {
	float windowSize[2] = { ofGetWidth(), ofGetHeight() };
	for (int i = 0; i < number; ++i)
	{
		parameters[i].pos += parameters[i].velocity * speed_slider;
		parameters[i].velocity += parameters[i].acceleration * speed_slider;
		wallHit(parameters[i], windowSize);
		for (auto& force_point : force_points) 
		{
			float distance = force_point.distance(parameters[i].pos);
			ofVec2f distance_vector(force_point - parameters[i].pos);
			ofVec2f force = (gravity_slider * mass_slider * parameters[i].mass * distance_vector) / pow(distance, 3);
			parameters[i].acceleration += force / parameters[i].mass;
		}
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
	std::cout << x << " " << y << "\n";
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
