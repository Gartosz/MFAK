#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::update() 
{
	system.update(dt);
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