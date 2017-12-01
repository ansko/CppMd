// ./md -style Fusion


#include <cmath>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>

#include "constants.cpp"

#include "bond.hpp"
#include "particle.hpp"
#include "particles_system.hpp"
#include "simulation_box.hpp"
#include "simulation_box_widget.hpp"
#include "potentials/potential_harmonic.hpp"

int NUM = 5;
float EPSILON = 0.000001;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    std::vector<std::shared_ptr<Particle> > particle_ptrs;
    for (int i = 0; i < NUM; ++i)
        for (int j = 0; j < NUM; ++j) {
            Particle p(1, 1, 
                       i * DEFAULT_LENGTH_SCALE,
                       j * DEFAULT_LENGTH_SCALE, 0, 0, 0, 0);
            std::shared_ptr<Particle> particle_ptr = std::make_shared<Particle>(p);
            particle_ptrs.push_back(particle_ptr);
        }

    std::vector<std::shared_ptr<Bond> > bond_ptrs;
    for (auto particle : particle_ptrs)
        for (auto otherParticle : particle_ptrs) {
            if (particle == otherParticle)
                continue;
            float dx = particle->x() - otherParticle->x();
            float dy = particle->y() - otherParticle->y();
            float dz = particle->z() - otherParticle->z();
            float dl = pow(pow(dx, 2) + pow(dy, 2) + pow(dz, 2), 0.5);
            if (dl > DEFAULT_LENGTH_SCALE * 1.9)
                continue;
            if (dl < EPSILON)
                continue;
            Bond bond(particle, otherParticle, dl);
            std::shared_ptr<Bond> bond_ptr = std::make_shared<Bond>(bond);
            bond_ptrs.push_back(bond_ptr);
        }
    particle_ptrs[0]->move(DEFAULT_LENGTH_SCALE / 5, DEFAULT_LENGTH_SCALE / 5, 0);

    PotentialHarmonic pot;
    std::shared_ptr<PotentialHarmonic> pot_ptr = 
        std::make_shared<PotentialHarmonic>(pot);

    ParticlesSystem pss(particle_ptrs, bond_ptrs, pot_ptr);
    std::shared_ptr<ParticlesSystem> pss_ptr =
        std::make_shared<ParticlesSystem>(pss);

    SimulationBox sb(pss_ptr);
    std::shared_ptr<SimulationBox> sb_ptr = std::make_shared<SimulationBox>(sb);

    SimulationBoxWidget w(sb_ptr);

    w.show();

    return app.exec();
}
