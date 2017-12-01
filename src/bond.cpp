#include "bond.hpp"


Bond::Bond(std::shared_ptr<Particle> particle1_ptr,
           std::shared_ptr<Particle> particle2_ptr,
           float bondLength) {
    this->particle1_ptr = particle1_ptr;
    this->particle2_ptr = particle2_ptr;
    float dx0 = particle2_ptr->x() - particle1_ptr->x();
    float dy0 = particle2_ptr->y() - particle1_ptr->y();
    float dz0 = particle2_ptr->z() - particle1_ptr->z();
    l0 = bondLength;//pow(pow(dx0, 2) + pow(dy0, 2) + pow(dz0, 2), 0.5);
};

float Bond::dl() {
    float dx = particle2_ptr->x() - particle1_ptr->x();
    float dy = particle2_ptr->y() - particle1_ptr->y();
    float dz = particle2_ptr->z() - particle1_ptr->z();
    float l = pow(pow(dx, 2) + pow(dy, 2) + pow(dz, 2), 0.5);
    return l0 - l;
};

std::shared_ptr<Particle> Bond::getParticle1_ptr() {
    return particle1_ptr;
};

std::shared_ptr<Particle> Bond::getParticle2_ptr() {
    return particle2_ptr;
};
