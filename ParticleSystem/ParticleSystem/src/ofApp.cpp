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
	ofEnableDepthTest();
	drawParticles();
	ofDisableDepthTest();
	camera.end();
}

void ofApp::createEmitters() 
	{
	auto snowEmitter = std::make_shared<ParticleEmitter>((float)15 * 0.45f, 1000, 0.001);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(300, 5, 300, 0));
		posGenerator->pos = glm::vec4{ 0.0, 200.0, 0.0, 0.0 };
		snowEmitter->addGenerator(posGenerator);
	}
	system.addEmitter(snowEmitter);
}