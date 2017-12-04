#include "potential_vdw_6_12.hpp"


float PotentialVDW_6_12::E(std::shared_ptr<Bond> bond_ptr)
{
    std::shared_ptr<Particle> par1_ptr = bond_ptr->getParticle1_ptr();
    std::shared_ptr<Particle> par2_ptr = bond_ptr->getParticle2_ptr();
    float x = par2_ptr->x() - par1_ptr->x();
    float y = par2_ptr->y() - par1_ptr->y();
    float z = par2_ptr->z() - par1_ptr->z();
    float l = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
    float l_nodim = VDW_RADIUS / l;
    float E = VDW_PRE_FACTOR * (pow(l_nodim, 12) - pow(l_nodim, 6));
    return E;
}

std::vector<float> PotentialVDW_6_12::F(std::shared_ptr<Bond> bond_ptr)
{
    std::shared_ptr<Particle> par1_ptr = bond_ptr->getParticle1_ptr();
    std::shared_ptr<Particle> par2_ptr = bond_ptr->getParticle2_ptr();
    float x = par2_ptr->x() - par1_ptr->x();
    float y = par2_ptr->y() - par1_ptr->y();
    float z = par2_ptr->z() - par1_ptr->z();
    float l = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
    float l_nodim = VDW_RADIUS / l;
    float F = VDW_PRE_FACTOR * (-pow(l_nodim, 13) + pow(l_nodim, 7));
    F_xyz[0] = F * x / l;
    F_xyz[1] = F * y / l;
    F_xyz[2] = F * z / l;
    return F_xyz;
}

