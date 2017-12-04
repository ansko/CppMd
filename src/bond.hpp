#pragma once

#include <cmath>

#include <memory>
#include <vector>

#include "particle.hpp"


class Bond
{
public:
    Bond(std::shared_ptr<Particle> particle1_ptr,
         std::shared_ptr<Particle> particle2_ptr, 
         float bondLength);
    std::shared_ptr<Particle> getParticle1_ptr();
    std::shared_ptr<Particle> getParticle2_ptr();
    float dl();
private:
    float l0;
    std::shared_ptr<Particle> particle1_ptr;
    std::shared_ptr<Particle> particle2_ptr;
};
