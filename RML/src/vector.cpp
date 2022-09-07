#include "vector.h"
#include "trig.h"
#include <cmath>

namespace RML
{
	Vector::Vector() : Tuple4(0, 0, 0, 0) {};

	Vector::Vector(const Tuple4 tuple) : Tuple4(tuple.x(), tuple.y(), tuple.z(), 0) {};

	Vector::Vector(const Tuple3<double> tuple) : Tuple4(tuple.x(), tuple.y(), tuple.z(), 0) {}

	Vector::Vector(const double x, const double y, const double z) : Tuple4(x, y, z, 0) {};

	Vector::Vector(const double x, const double y) : Tuple4(x, y, 0, 0) {};

	Vector::operator Tuple3<double>() const { return { m_x, m_y, m_z }; }

	Vector Vector::zero() { return { 0, 0, 0 }; }

	Vector Vector::one() { return { 1, 1, 1 }; }

	Vector Vector::up() { return { 0, 1, 0 }; }

	Vector Vector::down() { return { 0, -1, 0 }; }

	Vector Vector::right() { return { 1, 0, 0 }; }

	Vector Vector::left() { return { -1, 0, 0 }; }

	Vector Vector::forward() { return { 0, 0, 1 }; }

	Vector Vector::backward() { return { 0, 0, -1 }; }

	Vector Vector::cross(const Vector& a, const Vector& b)
	{
		return Vector(
			a.m_y * b.m_z - a.m_z * b.m_y,
			a.m_z * b.m_x - a.m_x * b.m_z,
			a.m_x * b.m_y - a.m_y * b.m_x
		);
	}

	double Vector::dot(const Vector& a, const Vector& b)
	{
		return a.m_x * b.m_x +
			a.m_y * b.m_y +
			a.m_z * b.m_z;
	}

	double Vector::angle(const Vector& a, const Vector& b)
	{
		return Trig::radians_to_degrees(
			acos(dot(a, b) / (a.magnitude() * b.magnitude()))
		);
	}

	double RML::Vector::signed_angle(const Vector& a, const Vector& b, const Vector& axis)
	{
		double unsignedAngle = angle(a, b);
		
		auto c = RML::Vector::cross(a, b);
		double s = -copysign(1.0, axis.x() * c.x() + axis.y() * c.y() + axis.z() * c.z());
		return s * unsignedAngle;
	}

	Vector Vector::reflect(const Vector& vector, const Vector& normal)
	{
		return vector - normal * 2 * dot(vector, normal);
	}

	double Vector::magnitude() const
	{
		return sqrt(
			pow(this->m_x, 2) +
			pow(this->m_y, 2) +
			pow(this->m_z, 2)
		);
	}

	Vector Vector::normalize()
	{
		*this = normalized();
		return *this;
	}

	Vector Vector::normalized() const
	{
		return Vector(*this / this->magnitude());
	}
}
