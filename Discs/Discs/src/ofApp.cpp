#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(speed_slider.setup("Modify speed", 1.0, 0.0, 10.0));
}

//--------------------------------------------------------------
void ofApp::update(){

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
void ofApp::draw(){
	float windowSize[2] = {ofGetWidth(), ofGetHeight()};
	for (int i = 0; i < number; ++i)
	{
		changeDirection(parameters[i], windowSize);
		parameters[i].pos += parameters[i].velocity * speed_slider;
		ofSetColor(ofColor(parameters[i].color[0], parameters[i].color[1], parameters[i].color[2]));
		ofDrawCircle(parameters[i].pos[0], parameters[i].pos[1], parameters[i].size);
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
