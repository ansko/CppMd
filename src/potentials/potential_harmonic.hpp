#pragma once

#include <cmath>

#include <iostream>
#include <memory>

#include "../particle.hpp"

#include "potential.hpp"


extern float K_HAR;


class PotentialHarmonic : public Potential
{
public:
    float E(std::shared_ptr<Bond> bond_ptr);
    std::vector<float> F(std::shared_ptr<Bond> bond_ptr);
};
