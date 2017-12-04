#pragma once


#include <memory>
#include <vector>

#include "../bond.hpp"


/*
    F = -grad E
    E_har = k * dl^2 / 2
    E_vdW = k * (pow(l_nodim, 12) - pow(l_nodim, 6))
*/


class Potential
{
public:
    virtual float E(std::shared_ptr<Bond> bond_ptr) = 0;
    virtual std::vector<float> F(std::shared_ptr<Bond> bond_ptr) = 0;
    std::vector<float> F_xyz{0., 0., 0.};
};
