#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vector.h"

class Particle
{
private:
    double mass = 1;
    Vector location;
    Vector velocity;
    Vector acceleration;
protected:
    friend std::ostream& operator<<(std::ostream& out, Particle& p);
    friend std::ostream& operator<<(std::ostream& out, Particle* p);
public:
    Particle();
    Particle(Vector location);
    double Mass();
    void Mass(double mass);
    Vector Location();
    void Location(Vector location);
    Vector Velocity();
    void Velocity(Vector velocity);
    Vector Acceleration();
    void Acceleration(Vector acceleration);
    void applyForce(Vector force);
    virtual void move();
};

#endif // PARTICLE_H
