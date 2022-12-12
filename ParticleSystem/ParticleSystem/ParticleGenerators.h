#pragma once
#include "ParticleSystem.h"
#include "glm/gtc/random.hpp"

class BoxPosGen : public ParticleGenerator
{
public:
    glm::vec4 pos{ 0.0 };
    glm::vec4 max_start_offset{ 0.0 };
public:
    BoxPosGen() { }

    virtual void generate(double dt, ParticleData* p, size_t start_index, size_t end_index) override;
};

