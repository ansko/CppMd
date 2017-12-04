#pragma once

#include <cmath>

extern float DEFAULT_MASS;
extern float DEFAULT_CHARGE;

class Particle
{
public:
    Particle();
    Particle(float m,
             float q,
             float x, float y, float z,
             float vx, float vy, float vz);
    float m() const;
    float q() const;
    float x() const;
    float y() const;
    float z() const;
    float vx() const;
    float vy() const;
    float vz() const;
    float E_kin();
    void move(float dx, float dy, float dz);
    void changeVelocities(float dvx, float dvy, float dvz);
private:
    float _m;
    float _q;
    float _x, _y, _z;
    float _vx, _vy, _vz;
};
