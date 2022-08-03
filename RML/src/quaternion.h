#pragma once
#include "tuple3.h"
#include "tuple4.h"
#include "point.h"

namespace RML
{
	class Quaternion
	{
	public:
		Quaternion(double w, double i, double j, double k);

		static Quaternion identity();

		static Quaternion angle_axis(double rotDegrees, Tuple3<double> axisNormal);

		Quaternion normalized() const;

		Quaternion& normalize();

		Quaternion inverse() const;

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
