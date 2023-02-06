#include "ofApp.h"

void ofApp::setup(){
	camera.setGlobalPosition({ 0, 40, 0 });
	camera.setTarget({ 50, 0, 10 });
	camera.setDistance(600);
	gui.setup();
	gui.setSize(250, 120);
	gui.add(system.dt.setup("Delta time", 0.5, 0.1, 1.15));
	gui.add(system.ks.setup("Elasticity", 2, 0.1, 15));
	gui.add(system.kd.setup("Dumping", 7, 0.1, 30));
	gui.add(system.g.setup("Gravity", -1, -10, 2));
	gui.add(system.wind.setup("Wind", glm::vec3{0, 0, 0.2}, glm::vec3{-5, -5, -5}, glm::vec3{5, 5, 5}));
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
