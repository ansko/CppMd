#pragma once

#include <iostream>
#include <memory>

#include "particles_system.hpp"


class SimulationBox
{
public:
    SimulationBox(std::shared_ptr<ParticlesSystem> particlesSystem_ptr);
    SimulationBox(std::shared_ptr<ParticlesSystem> particlesSystem_ptr,
                  float l);
    SimulationBox(std::shared_ptr<ParticlesSystem> particlesSystem_ptr,
                  float lx, float ly, float lz);
    std::shared_ptr<ParticlesSystem> getParticlesSystem_ptr();
    void update();
private:
    float _lx, _ly, _lz;
    std::shared_ptr<ParticlesSystem> particlesSystem_ptr;
};
