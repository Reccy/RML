#include "transform.h"
#include "trig.h"
#include <vector>

namespace RML
{
	Transform::Transform() :
		position(),
		rotation(Quaternion::identity()),
		scaling(1, 1, 1) {};

	Vector Transform::up() const { return rotation * Vector::up(); }
	Vector Transform::down() const { return rotation * Vector::down(); }
	Vector Transform::left() const { return rotation * Vector::left(); }
	Vector Transform::right() const { return rotation * Vector::right(); }
	Vector Transform::forward() const { return rotation * Vector::forward(); }
	Vector Transform::backward() const { return rotation * Vector::backward(); }

	Transform& Transform::translate(const double x, const double y, const double z)
	{
		position = Tuple3<double>(position) + Tuple3<double>(x, y, z);
		return *this;
	}

	Transform& Transform::rotate(const double xDeg, const double yDeg, const double zDeg)
	{
		rotation = rotation * Quaternion::euler_angles(xDeg, yDeg, zDeg);
		return *this;
	}

	Transform& Transform::scale(const double x, const double y, const double z)
	{
		scaling = { x * scaling.x(), y * scaling.y(), z * scaling.z() };
		return *this;
	}

	void Transform::look_at(RML::Point target)
	{
		look_at(target, RML::Vector::forward());
	}

	void Transform::look_at(RML::Point target, RML::Vector up)
	{
		RML::Vector dirToTarget = RML::Vector(target - position).normalized();

		RML::Quaternion fromToRot = RML::Quaternion::from_to(up, dirToTarget);

		RML::Vector actualVec = fromToRot * RML::Vector::forward();

		rotation = fromToRot;
	}

	const Matrix<double, 4, 4> Transform::get_transposed()
	{
		return matrix().transpose();
	}

	const Matrix<double, 4, 4> Transform::get_inverted()
	{
		return matrix().invert();
	}

	const Matrix<double, 4, 4> Transform::matrix() const
	{
		Matrix<double, 4, 4> tMatrix({
			1, 0, 0, position.x(),
			0, 1, 0, position.y(),
			0, 0, 1, position.z(),
			0, 0, 0, 1
		});

		Matrix<double, 4, 4> rMatrix = rotation.matrix();

		Matrix<double, 4, 4> sMatrix({
			scaling.x(), 0,           0,           0,
			0,           scaling.y(), 0,           0,
			0,           0,           scaling.z(), 0,
			0,           0,           0,           1
		});

		auto result = tMatrix * rMatrix * sMatrix;
		return result;
	}

	Tuple4<double> Transform::operator*(const Tuple4<double>& tuple) const
	{
		return matrix() * tuple;
	}

	bool Transform::operator==(const Transform& other) const
	{
		return matrix() == other.matrix();
	}

	bool Transform::operator!=(const Transform& other) const
	{
		return !((*this) == other);
	}
}
