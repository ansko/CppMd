#pragma once

#include <cmath>

#include <iostream>
#include <memory>

#include "../particle.hpp"

#include "potential.hpp"


extern float VDW_PRE_FACTOR;
extern float VDW_RADIUS;

class PotentialVDW_6_12 : public Potential
{
public:
    float E(std::shared_ptr<Bond> bond_ptr);
    std::vector<float> F(std::shared_ptr<Bond> bond_ptr);
};
