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
	auto snow_emitter = std::make_shared<ParticleEmitter>((float)3, 1000, 0.001);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(300, 5, 300, 0));
		posGenerator->pos = glm::vec4{ 0.0, 200.0, 0.0, 0.0 };
		snow_emitter->addGenerator(posGenerator);
	}

	system.addEmitter(snow_emitter);

	/*auto flame_emitter = std::make_shared<ParticleEmitter>((float)1, 500, 0.002);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(10, 5, 10, 0));
		posGenerator->pos = glm::vec4{ 0.0, floor_level, 0.0, 0.0 };
		posGenerator->color = ofColor::orangeRed;
		flame_emitter->init_velocity_range[0] = glm::vec4(-0.15, 0.25, -0.15, 0);
		flame_emitter->init_velocity_range[1] = glm::vec4(0.15, 0.8, 0.15, 0);
		flame_emitter->addGenerator(posGenerator);
	}

	system.addEmitter(flame_emitter);

	auto smoke_emitter = std::make_shared<ParticleEmitter>((float)1, 600, 0.0001);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(7, 5, 7, 0));
		posGenerator->pos = glm::vec4{ 0.0, floor_level + 20, 0.0, 0.0 };
		posGenerator->color = ofColor::dimGrey;
		smoke_emitter->init_velocity_range[0] = glm::vec4(-0.2, 0.15, -0.2, 0);
		smoke_emitter->init_velocity_range[1] = glm::vec4(0.2, 0.3, 0.2, 0);
		smoke_emitter->addGenerator(posGenerator);
	}

	system.addEmitter(smoke_emitter);

	auto glittering_emitter1 = std::make_shared<ParticleEmitter>((float)1, 100);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(15, 50, 10, 0));
		posGenerator->pos = glm::vec4{ 100.0, floor_level + 50.0, 0, 0.0 };
		posGenerator->color = ofColor::yellow;
		glittering_emitter1->addGenerator(posGenerator);
	}

	system.addEmitter(glittering_emitter1);

	auto glittering_emitter2 = std::make_shared<ParticleEmitter>((float)1, 100);
	{
		auto posGenerator = std::make_shared<BoxPosGen>(glm::vec4(15, 50, 10, 0));
		posGenerator->pos = glm::vec4{ -100.0, floor_level + 50.0, 0, 0.0 };
		posGenerator->color = ofColor::yellow;
		glittering_emitter2->addGenerator(posGenerator);
	}

	system.addEmitter(glittering_emitter2);*/
}