#include "ofApp.h"

void ofApp::setup(){
	camera.setGlobalPosition({ 0, 40, 0 });
	camera.setTarget({ 50, 0, 10 });
	camera.setDistance(600);
	gui.setup();
	gui.add(system.dt.setup("Delta time", 0.5, 0.1, 1.15));
	gui.add(system.ks.setup("Elasticity", 0.2, 0.1, 5));
	gui.add(system.kd.setup("Dumping", 3, 0.1, 10));
	gui.add(system.g.setup("Gravity", -0.1, -3, 1));
	gui.add(system.wind.setup("Wind", glm::vec3{0, 0, 0}, glm::vec3{-0.01, -0.01, -0.01}, glm::vec3{0.01, 0.01, 0.01}));
}

void ofApp::update(){
	system.update();
}

void ofApp::draw()
{
	camera.begin();
	system.draw();
	camera.end();
	gui.draw();
}
