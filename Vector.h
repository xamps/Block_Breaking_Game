#pragma once
#include <ostream>
#include <cmath>

class Vector
{
private:
	double toRadians(double degree);
	friend std::ostream& operator<<(std::ostream&, Vector&);
    friend std::ostream& operator<<(std::ostream&, Vector*);
	friend bool operator==(Vector&, Vector&);

public:
	double x;
	double y;
	double z;

	Vector();

	Vector(double x, double y);

	Vector(double x, double y, double z);

    int intX();
    int intY();
    int intZ();

    void magnitude(double m);

    double magnitude();

    double magnitude2();

    void normalize();

    void add(Vector v);

    static Vector add(Vector v1, Vector v2);

    void sub(Vector v);

    static Vector sub(Vector v1, Vector v2);

    void mul(double f);

    static Vector mul(Vector v1, double f);

    void div(double f);

    static Vector div(Vector v1, double f);

    void rotateZ(double degrees);

    void rotateY(double degrees);

    void rotateX(double degrees);

    void translateX(double tx);

    void translateY(double ty);

    void translateZ(double tz);

    void translate(double t);

    void translate(double tx, double ty);

    void translate(double tx, double ty, double tz);

    void scaleX(double sx);

    void scaleY(double sy);

    void scaleZ(double sz);

    void scale(double s);

    void scale(double sx, double sy);

    void scale(double sx, double sy, double sz);

    void mirrorX();

    void mirrorY();

    void mirrorZ();

    void mirror();

    void limit(double max);

    void limit(double min, double max);

    Vector copy();
};
