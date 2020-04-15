#include "particle.h"

Particle::Particle()
{
}
Particle::Particle(Vector location)
{
    this->location = location;
}
double Particle::Mass()
{
    return this->mass;
}
void Particle::Mass(double mass)
{
    this->mass = mass;
}
Vector Particle::Location()
{
    return this->location;
}
void Particle::Location(Vector location)
{
    this->location = location;
}
Vector Particle::Velocity()
{
    return this->velocity;
}
void Particle::Velocity(Vector velocity)
{
    this->velocity = velocity;
}
Vector Particle::Acceleration()
{
    return this->acceleration;
}
void Particle::Acceleration(Vector acceleration)
{
    this->acceleration = acceleration;
}
void Particle::applyForce(Vector force)
{
    acceleration.add(Vector::div(force, mass));
}
void Particle::move()
{
    velocity.add(acceleration);
    location.add(velocity);
    acceleration.mul(0);
}
std::ostream& operator<<(std::ostream& out, Particle& p) {
    return out << "{mass: " << p.mass << ", origin: " << p.location << ", velocity: " << p.velocity << "}";
}

std::ostream& operator<<(std::ostream& out, Particle* p) {
    return out << "{mass: " << p->mass << ", origin: " << p->location << ", velocity: " << p->velocity << "}";
}
