#include "transform.h"
#include "trig.h"
#include <vector>

namespace RML
{
	Transform::Transform() : m_matrix(Matrix<double, 4, 4>::identity()) {};

	Transform& Transform::translate(const double x, const double y, const double z)
	{
		Matrix<double, 4, 4> translationMatrix = Matrix<double, 4, 4>::identity();
		translationMatrix(0, 3) = x;
		translationMatrix(1, 3) = y;
		translationMatrix(2, 3) = z;

		m_matrix = translationMatrix * m_matrix;

		return *this;
	}

	Transform& Transform::scale(const double x, const double y, const double z)
	{
		Matrix<double, 4, 4> scaleMatrix = Matrix<double, 4, 4>::identity();
		scaleMatrix(0, 0) = x;
		scaleMatrix(1, 1) = y;
		scaleMatrix(2, 2) = z;

		m_matrix = scaleMatrix * m_matrix;

		return *this;
	}

	Transform& Transform::rotate(const double x, const double y, const double z)
	{
		const double xRad = Trig::degrees_to_radians(x);
		const double yRad = Trig::degrees_to_radians(y);
		const double zRad = Trig::degrees_to_radians(z);

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

		m_matrix = zRotationMatrix * yRotationMatrix * xRotationMatrix * m_matrix;

		return *this;
	}

	Transform& Transform::shear(const double xY, const double xZ, const double yX, const double yZ, const double zX, const double zY)
	{
		Matrix<double, 4, 4> shearMatrix = Matrix<double, 4, 4>({
			1, xY, xZ, 0,
			yX, 1, yZ, 0,
			zX, zY, 1, 0,
			0, 0, 0, 1
			});

		m_matrix = shearMatrix * m_matrix;

		return *this;
	}

	Transform& Transform::transpose()
	{
		m_matrix = m_matrix.transpose();

		return *this;
	}

	Transform& Transform::invert()
	{
		if (m_matrix.invertible())
		{
			m_matrix = m_matrix.invert();
		}

		return *this;
	}

	const Matrix<double, 4, 4> Transform::matrix() const
	{
		return m_matrix;
	}

	Tuple4<double> Transform::operator*(const Tuple4<double>& tuple) const
	{
		return m_matrix * tuple;
	}

	bool Transform::operator==(const Transform& other) const
	{
		return m_matrix == other.m_matrix;
	}

	bool Transform::operator!=(const Transform& other) const
	{
		return !((*this) == other);
	}
}
