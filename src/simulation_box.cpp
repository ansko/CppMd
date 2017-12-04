#include "simulation_box.hpp"


SimulationBox::SimulationBox(
    std::shared_ptr<ParticlesSystem> particlesSystem_ptr)
{
    this->particlesSystem_ptr = particlesSystem_ptr;
}

SimulationBox::SimulationBox(
    std::shared_ptr<ParticlesSystem> particlesSystem_ptr,
    float l)
{
    this->particlesSystem_ptr = particlesSystem_ptr;
    _lx = l;
    _ly = l;
    _lz = l;
}

std::shared_ptr<ParticlesSystem> SimulationBox::getParticlesSystem_ptr()
{
    return particlesSystem_ptr;
}

void SimulationBox::update()
{
    particlesSystem_ptr->update();
}
