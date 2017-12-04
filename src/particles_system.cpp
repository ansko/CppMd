#include "particles_system.hpp"


ParticlesSystem::ParticlesSystem(
    std::vector<std::shared_ptr<Particle> > particle_ptrs,
    std::vector<std::shared_ptr<Bond> > bond_ptrs,
    std::shared_ptr<Potential> parameterization_ptr)
{
    this->particle_ptrs = particle_ptrs;
    this->bond_ptrs = bond_ptrs;
    this->parameterization_ptr = parameterization_ptr;
}

std::vector<std::shared_ptr<Particle> > ParticlesSystem::getParticle_ptrs()
{
    return particle_ptrs;
}

std::vector<std::shared_ptr<Bond> > ParticlesSystem::getBond_ptrs()
{
    return bond_ptrs;
}

float ParticlesSystem::energy()
{
    return 0;
}

void ParticlesSystem::update()
{
    std::vector<std::vector<std::vector<float> > > forces_ij;
    std::vector<std::vector<float> > forces_i;
    std::vector<std::shared_ptr<Particle> > particle_ptrs_tmp;
    int par_num = particle_ptrs.size();
    int bonds_num = bond_ptrs.size();
    float e_pot = 0;
    float e_kin = 0;

    // forces between bonds
    std::map<std::shared_ptr<Particle>, std::vector<float> > particle_force_map;
    std::map<std::shared_ptr<Particle>, float> particle_energy_map;
    for (auto bond_ptr : bond_ptrs) {
         std::vector<float> f = parameterization_ptr->F(bond_ptr);
         float e = parameterization_ptr->E(bond_ptr);
         if (particle_force_map.find(bond_ptr->getParticle1_ptr()) ==
                 particle_force_map.end())
             particle_force_map[bond_ptr->getParticle1_ptr()] = f;
         else {
             particle_force_map[bond_ptr->getParticle1_ptr()][0] += f[0];
             particle_force_map[bond_ptr->getParticle1_ptr()][1] += f[1];
             particle_force_map[bond_ptr->getParticle1_ptr()][2] += f[2];
         }
         e_pot += e;
         f[0] *= -1;
         f[1] *= -1;
         f[2] *= -1;
         if (particle_force_map.find(bond_ptr->getParticle2_ptr()) ==
                 particle_force_map.end())
             particle_force_map[bond_ptr->getParticle2_ptr()] = f;
         else {
             particle_force_map[bond_ptr->getParticle2_ptr()][0] += f[0];
             particle_force_map[bond_ptr->getParticle2_ptr()][1] += f[1];
             particle_force_map[bond_ptr->getParticle2_ptr()][2] += f[2];
         }
    }

    for (auto particle_ptr : particle_ptrs){
        particle_ptr->changeVelocities(
            particle_force_map[particle_ptr][0] / DEFAULT_MASS * DT,
            particle_force_map[particle_ptr][1] / DEFAULT_MASS * DT,
            particle_force_map[particle_ptr][2] / DEFAULT_MASS * DT);
        particle_ptr->move(particle_ptr->vx() * DT,
                           particle_ptr->vy() * DT,
                           particle_ptr->vz() * DT);
        e_kin += particle_ptr->E_kin();
    }

    // Energy doesn't concerve...
    std::cout << e_pot + e_kin << " " << e_pot << " " << e_kin << std::endl;

    return;
}
