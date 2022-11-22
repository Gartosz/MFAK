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
	ofVec2f force_point(ofGetWidth() / 2, ofGetHeight() / 2);
	for (int i = 0; i < number; ++i)
	{
		parameters[i].pos += parameters[i].velocity * speed_slider;
		parameters[i].velocity += parameters[i].acceleration * speed_slider;
		float distance = force_point.distance(parameters[i].pos);
		ofVec2f distance_vector(force_point - parameters[i].pos);
		ofVec2f force = (gravity_slider * mass_slider * parameters[i].mass * distance_vector) / pow(distance, 3);
		parameters[i].acceleration += force / parameters[i].mass;
}

bool ofApp::exceedsBorder(float const &position, float const &size, float const &borderSize)
{
	if (position + size >= borderSize || position - size <= 0)
		return true;
	return false;
}

void ofApp::changeDirection(disk_parameters& parameter, float const *windowSize)
{
	if (exceedsBorder(parameter.pos[0], parameter.size, windowSize[0]))
		parameter.velocity[0] *= -1;

	if (exceedsBorder(parameter.pos[1], parameter.size, windowSize[1]))
		parameter.velocity[1] *= -1;
}


//--------------------------------------------------------------
void ofApp::draw() {
	float windowSize[2] = {ofGetWidth(), ofGetHeight()};
	for (int i = 0; i < number; ++i)
	{
		changeDirection(parameters[i], windowSize);
		parameters[i].pos += parameters[i].velocity * speed_slider;
		ofSetColor(parameters[i].color);
		ofDrawCircle(parameters[i].pos, parameters[i].size);
	}
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
