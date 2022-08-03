#include "transform.h"
#include "trig.h"
#include <vector>

namespace RML
{
	Transform::Transform() :
		m_translation(),
		m_rotation(Matrix<double, 4, 4>::identity()),
		m_scale(1, 1, 1) {};

	Transform& Transform::translate(const double x, const double y, const double z)
	{
		m_translation += {x, y, z};
		return *this;
	}

	Transform& Transform::rotate(const double xDeg, const double yDeg, const double zDeg)
	{
		const double xRad = Trig::degrees_to_radians(xDeg);
		const double yRad = Trig::degrees_to_radians(yDeg);
		const double zRad = Trig::degrees_to_radians(zDeg);

		Matrix<double, 4, 4> xRotationMatrix = Matrix<double, 4, 4>({
			1, 0, 0, 0,
			0, cos(xRad), -sin(xRad), 0,
			0, sin(xRad), cos(xRad), 0,
			0, 0, 0, 1
			});

		Matrix<double, 4, 4> yRotationMatrix = Matrix<double, 4, 4>({
			cos(yRad), 0, sin(yRad), 0,
			0, 1, 0, 0,
			-sin(yRad), 0, cos(yRad), 0,
			0, 0, 0, 1
			});

		Matrix<double, 4, 4> zRotationMatrix = Matrix<double, 4, 4>({
			cos(zRad), -sin(zRad), 0, 0,
			sin(zRad), cos(zRad), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
			});

		m_rotation = zRotationMatrix * yRotationMatrix * xRotationMatrix * m_rotation;

		return *this;
	}

	Transform& Transform::scale(const double x, const double y, const double z)
	{
		m_scale = { x * m_scale.x(), y * m_scale.y(), z * m_scale.z() };
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
			1, 0, 0, m_translation.x(),
			0, 1, 0, m_translation.y(),
			0, 0, 1, m_translation.z(),
			0, 0, 0, 1
		});

		Matrix<double, 4, 4> rMatrix = m_rotation;

		Matrix<double, 4, 4> sMatrix({
			m_scale.x(), 0,           0,           0,
			0,           m_scale.y(), 0,           0,
			0,           0,           m_scale.z(), 0,
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
