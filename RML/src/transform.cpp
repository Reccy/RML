#include "transform.h"
#include "trig.h"
#include <vector>

namespace RML
{
	Transform::Transform() :
		position(),
		rotation(Quaternion::identity()),
		scaling(1, 1, 1) {};

	Transform& Transform::translate(const double x, const double y, const double z)
	{
		position += {x, y, z};
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
