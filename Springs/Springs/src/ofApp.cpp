#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	camera.begin();
	for (int y = 0; y < system.coordinates.size(); ++y)
	{
		for (int x = 1; x < system.coordinates[y].size() - 1; ++x)
		{
			ofDrawLine(system.coordinates[y][x], system.coordinates[y][0], system.coordinates[y][x + 1], system.coordinates[y][0]);
			ofDrawCircle(system.coordinates[y][x + 1], system.coordinates[y][0], system.size);
			if (y != system.coordinates.size() - 1)
			{
				ofDrawLine(system.coordinates[y][x], system.coordinates[y][0], system.coordinates[y][x], system.coordinates[y + 1][0]);
				if (x == system.coordinates[y].size() - 2)
					ofDrawLine(system.coordinates[y][x + 1], system.coordinates[y][0], system.coordinates[y][x + 1], system.coordinates[y + 1][0]);
			}
		}
	}
	camera.end();
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
