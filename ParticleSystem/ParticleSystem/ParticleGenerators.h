#pragma once
#include "ParticleSystem.h"
#include "glm/gtc/random.hpp"

class BoxPosGen : public ParticleGenerator
{
public:
    glm::vec4 pos{ 0.0 };
    glm::vec4 max_start_offset{ 0.0 };
public:
    BoxPosGen(glm::vec4 offset) 
    { 
        max_start_offset = glm::vec4(offset);
    }

    virtual void generate(double dt, ParticleData* p, size_t start_index, size_t end_index) override;
};

class VelocityRangeGen : public ParticleGenerator
{
public:
    std::shared_ptr<std::vector<glm::vec2>> velocity_range;

public:
    VelocityRangeGen(std::vector < glm::vec2 > range)
    {
        velocity_range = std::make_shared<std::vector<glm::vec2>>(range);
    }

    virtual void generate(double dt, ParticleData* p, size_t start_index, size_t end_index) override;
};