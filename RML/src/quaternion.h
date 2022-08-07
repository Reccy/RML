#pragma once
#include "matrix.h"
#include "tuple3.h"
#include "tuple4.h"
#include "point.h"

// Some code adapted from: https://gist.github.com/aeroson/043001ca12fe29ee911e

namespace RML
{
	class Quaternion
	{
	public:
		Quaternion(double w, double i, double j, double k);

		Quaternion(Matrix<double, 4, 4> matrix);

		static Quaternion identity();

		static Quaternion euler_angles(double xDegrees, double yDegrees, double zDegrees);

		static Quaternion angle_axis(double rotDegrees, Tuple3<double> axisNormal);

		static Quaternion from_to(const Vector& fromDirection, const Vector& toDirection);

		Quaternion normalized() const;

		Quaternion& normalize();

		Quaternion inverse() const;

		Matrix<double, 4, 4> matrix() const;

		double magnitude() const;
	
		double w() const;
		double i() const;
		double j() const;
		double k() const;

		Tuple4<double> operator*(const Tuple4<double>& t) const;
		Quaternion operator*(const Quaternion& other) const;
		bool operator!=(const Quaternion& other) const;
		bool operator==(const Quaternion& other) const;
	private:
		double m_w, m_i, m_j, m_k;
	};

	std::ostream& operator<<(std::ostream& os, const Quaternion& q);
}
