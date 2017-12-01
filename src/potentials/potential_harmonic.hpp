#pragma once

#include "potential.hpp"
#include "potential_harmonic.hpp"


extern float R0;
extern float K;


class PotentialHarmonic : public Potential {
public:
    float E(std::shared_ptr<Bond> bond_ptr);
    std::vector<float> F(std::shared_ptr<Bond> bond_ptr);
};
