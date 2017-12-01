#pragma once


#include <memory>
#include <vector>

#include "../bond.hpp"

class Potential {
public:
    virtual float E(std::shared_ptr<Bond> bond_ptr) = 0;
    virtual std::vector<float> F(std::shared_ptr<Bond> bond_ptr) = 0;
    std::vector<float> F_xyz{0., 0., 0.};
};
