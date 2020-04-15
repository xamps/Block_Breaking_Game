#include "Vector.h"

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

int Vector::intX()
{
    return static_cast<int>(x);
}

int Vector::intY()
{
    return static_cast<int>(y);
}

int Vector::intZ()
{
    return static_cast<int>(z);
}

void Vector::magnitude(double m)
{
	normalize();
	mul(m);
}

double Vector::magnitude()
{
	return std::sqrt(magnitude2());
}

double Vector::magnitude2()
{
	return (x * x + y * y + z * z);
}

void Vector::normalize()
{
	div(magnitude());
}

void Vector::add(Vector v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

Vector Vector::add(Vector v1, Vector v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

void Vector::sub(Vector v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

Vector Vector::sub(Vector v1, Vector v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

void Vector::mul(double f)
{
	x *= f;
	y *= f;
	z *= f;
}

Vector Vector::mul(Vector v1, double f)
{
    return Vector(v1.x * f, v1.y + f, v1.z + f);
}

void Vector::div(double f)
{
	if (f == 0)
	{
		return;
	}
	x /= f;
	y /= f;
	z /= f;
}

Vector Vector::div(Vector v1, double f)
{
    return Vector(v1.x / f, v1.y / f, v1.z / f);
}

double Vector::toRadians(double degree)
{
	return (degree * M_PI) / 180;
}

void Vector::rotateZ(double degrees)
{
    double radians = toRadians(degrees);

	double newX = (1 * x * std::cos(radians)) + (-1 * y * std::sin(radians));
	double newY = (1 * x * std::sin(radians)) + (1 * y * std::cos(radians));
	double newZ = z;

	x = newX;
	y = newY;
	z = newZ;
}

void Vector::rotateY(double degrees)
{
    double radians = toRadians(degrees);

	double newX = (1 * x * std::cos(radians)) + (1 * z * std::sin(radians));
	double newY = y;
	double newZ = (-1 * x * std::sin(radians)) + (1 * z * std::cos(radians));

	x = newX;
	y = newY;
	z = newZ;
}

void Vector::rotateX(double degrees)
{
    double radians = toRadians(degrees);

	double newX = x;
	double newY = (1 * y * std::cos(radians)) + (-1 * z * std::sin(radians));
	double newZ = (1 * y * std::sin(radians)) + (1 * z * std::cos(radians));

	x = newX;
	y = newY;
	z = newZ;
}

void Vector::translateX(double tx)
{
	x += tx;
}

void Vector::translateY(double ty)
{
	y += ty;
}

void Vector::translateZ(double tz)
{
	z += tz;
}

void Vector::translate(double t)
{
	x += t;
	y += t;
	z += t;
}

void Vector::translate(double tx, double ty)
{
	x += tx;
	y += ty;
}

void Vector::translate(double tx, double ty, double tz)
{
	x += tx;
	y += ty;
	z += tz;
}

void Vector::scaleX(double sx)
{
	x *= sx;
}

void Vector::scaleY(double sy)
{
	y *= sy;
}

void Vector::scaleZ(double sz)
{
	z *= sz;
}

void Vector::scale(double s)
{
	x *= s;
	y *= s;
	z *= s;
}

void Vector::scale(double sx, double sy)
{
	x *= sx;
	y *= sy;
}

void Vector::scale(double sx, double sy, double sz)
{
	x *= sx;
	y *= sy;
	z *= sz;
}

void Vector::mirrorX()
{
    x = -x;
}

void Vector::mirrorY()
{
    y = -y;
}

void Vector::mirrorZ()
{
    z = -z;
}

void Vector::mirror()
{
    x = -x;
    y = -y;
    z = -z;
}

void Vector::limit(double max)
{
	limit(0, max);
}

void Vector::limit(double min, double max)
{
	if (x > max)
	{
		x = max;
	}
	else if (x < min)
	{
		x = min;
	}
    if (y > max)
	{
		y = max;
	}
	else if (y < min)
	{
		y = min;
	}
	if (z > max)
	{
		z = max;
	}
	else if (z < min)
	{
		z = min;
	}
}

Vector Vector::copy()
{
    return Vector(x, y, z);
}

bool operator== (Vector& lhs, Vector& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

std::ostream& operator<<(std::ostream& out, Vector& v) {
	return out << "{x: " << v.x << ", y: " << v.y << ", z: " << v.z << "}";
}

std::ostream& operator<<(std::ostream& out, Vector* v) {
    return out << "{x: " << v->x << ", y: " << v->y << ", z: " << v->z << "}";
}
