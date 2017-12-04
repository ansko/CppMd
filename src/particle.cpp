#include "particle.hpp"


Particle::Particle()
{
    _m = DEFAULT_MASS;
    _q = DEFAULT_CHARGE;
    _x = 0;
    _y = 0;
    _z = 0;
    _vx = 0;
    _vy = 0;
    _vz = 0;
}

Particle::Particle(float m,
                   float q,
                   float x, float y, float z,
                   float vx, float vy, float vz)
{
    _m = m;
    _q = q;
    _x = x;
    _y = y;
    _z = z;
    _vx = vx;
    _vy = vy;
    _vz = vz;
}

float Particle::m() const
{
    return _m;
};

float Particle::q() const
{
    return _q;
};

float Particle::x() const
{
    return _x;
};

float Particle::y() const
{
    return _y;
};

float Particle::z() const
{
    return _z;
};

float Particle::vx() const
{
    return _vx;
};

float Particle::vy() const
{
    return _vy;
};

float Particle::vz() const
{
    return _vz;
};

float Particle::E_kin()
{
    return _m * pow(pow(_vx, 2) + pow(_vy, 2) + pow(_vz, 2), 0.5) / 2;
};

void Particle::move(float dx, float dy, float dz)
{
    _x += dx;
    _y += dy;
    _z += dz;
};

void Particle::changeVelocities(float dvx, float dvy, float dvz)
{
    _vx += dvx;
    _vy += dvy;
    _vz += dvz;
}
