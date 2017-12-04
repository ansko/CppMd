#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include <QTimer>
#include <QWidget>

#include "bond.hpp"
#include "particle.hpp"
#include "potentials/potential_harmonic.hpp"

extern float DT;


class ParticlesSystem : public QObject // should be derived from QObject to use QTimer...
{
    Q_OBJECT
public:
    ParticlesSystem(std::vector<std::shared_ptr<Particle> > particle_ptrs,
                    std::vector<std::shared_ptr<Bond> > bonds_ptrs,
                    std::shared_ptr<Potential> parameterization_ptr);
    std::vector<std::shared_ptr<Particle> > getParticle_ptrs();
    std::vector<std::shared_ptr<Bond> > getBond_ptrs();
    float energy();
public slots:
    void update();
private:
    QTimer* thisTimer_ptr;
    std::vector<std::shared_ptr<Particle> > particle_ptrs;
    std::vector<std::shared_ptr<Bond> > bond_ptrs;
    std::shared_ptr<Potential> parameterization_ptr;
};
