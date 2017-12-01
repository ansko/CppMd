#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <vector>

#include "bond.hpp"
#include "particle.hpp"
#include "potentials/potential_harmonic.hpp"

extern float DT;


class ParticlesSystem {
public:
    ParticlesSystem(std::vector<std::shared_ptr<Particle> > particle_ptrs,
                    std::vector<std::shared_ptr<Bond> > bonds_ptrs,
                    std::shared_ptr<PotentialHarmonic> parameterization_ptr);
    std::vector<std::shared_ptr<Particle> > getParticle_ptrs();
    std::vector<std::shared_ptr<Bond> > getBond_ptrs();
    float energy();
    void update();
private:
    std::vector<std::shared_ptr<Particle> > particle_ptrs;
    std::vector<std::shared_ptr<Bond> > bond_ptrs;
    std::shared_ptr<PotentialHarmonic> parameterization_ptr;
};
