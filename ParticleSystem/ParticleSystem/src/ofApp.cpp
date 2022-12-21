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

void ofApp::update() 
{
	system.update(10);
}

void ofApp::drawParticles()
{
	for (auto& particle : system.data.particles)
	{
		if (!particle.is_alive)
			break;
		ofSetColor(particle.color);
		ofDrawSphere(particle.pos, particle.size);
	}
}

void ofApp::draw() {
	camera.begin();
	//ofEnableDepthTest();
	drawParticles();
	//ofDisableDepthTest();
	camera.end();
}

void ofApp::createEmitters() {
	auto particleEmitter = std::make_shared<ParticleEmitter>((float)15 * 0.45f, 2000);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(500.0);
		posGenerator->pos = glm::vec4{ 0.0, 0.0, 0.0, 0.0 };
		particleEmitter->addGenerator(posGenerator);
	}
	system.addEmitter(particleEmitter);
}