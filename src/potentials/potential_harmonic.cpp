#include <iostream>
#include <memory>

#include "../particle.hpp"
#include "potential_harmonic.hpp"


float PotentialHarmonic::E(std::shared_ptr<Bond> bond_ptr) {
    return 0;
}

std::vector<float> PotentialHarmonic::F(std::shared_ptr<Bond> bond_ptr) {
    std::shared_ptr<Particle> par1_ptr = bond_ptr->getParticle1_ptr();
    std::shared_ptr<Particle> par2_ptr = bond_ptr->getParticle2_ptr();
    float x = par2_ptr->x()- par1_ptr->x();
    float y = par2_ptr->y()- par1_ptr->y();
    float z = par2_ptr->z()- par1_ptr->z();
    float l = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
    float F = -K * bond_ptr->dl();
    F_xyz[0] = F * x / l;
    F_xyz[1] = F * y / l;
    F_xyz[2] = F * z / l;
    return F_xyz;
}

