#include "quaternion.h"
#include "trig.h"

namespace RML
{
	Quaternion::Quaternion(double w, double i, double j, double k)
		: m_w(w),
		  m_i(i),
		  m_j(j),
		  m_k(k)
	{}

	Quaternion Quaternion::identity()
	{
		return Quaternion(1, 0, 0, 0);
	}

	Quaternion Quaternion::angle_axis(double rotDegrees, Tuple3<double> axisNormal)
	{
		double d = Trig::degrees_to_radians(rotDegrees);

		double s = sin(d / 2.0);
		
		double w = cos(d / 2.0);
		double i = axisNormal.x() * s;
		double j = axisNormal.y() * s;
		double k = axisNormal.z() * s;

		Quaternion result(w, i, j, k);
		return result.normalized();
	}

	Quaternion Quaternion::normalized() const
	{
		Quaternion copy(*this);
		return copy.normalize();
	}

	Quaternion& Quaternion::normalize()
	{
		double mag = magnitude();

		m_w = m_w / mag;
		m_i = m_i / mag;
		m_j = m_j / mag;
		m_k = m_k / mag;

		return *this;
	}

	Quaternion Quaternion::inverse() const
	{
		Quaternion result = Quaternion(*this);

		result.m_i = -result.m_i;
		result.m_j = -result.m_j;
		result.m_k = -result.m_k;

		return result;
	}

	double Quaternion::magnitude() const
	{
		return sqrt(
			  pow(w(), 2)
			+ pow(i(), 2)
			+ pow(j(), 2)
			+ pow(k(), 2)
		);
	}

	double Quaternion::w() const { return m_w; }
	double Quaternion::i() const { return m_i; }
	double Quaternion::j() const { return m_j; }
	double Quaternion::k() const { return m_k; }

	Tuple4<double> Quaternion::operator*(const Tuple4<double>& t) const
	{
		Quaternion tq(t.w(), t.x(), t.y(), t.z());
		Quaternion a = *this * tq;
		Quaternion b = a * inverse();
		return { b.i(), b.j(), b.k(), b.w() };
	}

	Quaternion Quaternion::operator*(const Quaternion& other) const
	{
		return {
			m_w * other.m_w - m_i * other.m_i - m_j * other.m_j - m_k * other.m_k,  // w
			m_w * other.m_i + m_i * other.m_w - m_j * other.m_k + m_k * other.m_j,  // i
			m_w * other.m_j + m_i * other.m_k + m_j * other.m_w - m_k * other.m_i,  // j
			m_w * other.m_k - m_i * other.m_j + m_j * other.m_i + m_k * other.m_w   // k
		};
	}

	bool Quaternion::operator!=(const Quaternion& other) const
	{
		return !(*this == other);
	}

	bool Quaternion::operator==(const Quaternion& other) const
	{
		return m_w == other.m_w
			&& m_i == other.m_i
			&& m_j == other.m_j
			&& m_k == other.m_k;
	}

	std::ostream& operator<<(std::ostream& os, const Quaternion& q)
	{
		os << q.w() << ", " << q.i() << ", " << q.j() << ", " << q.k();
		return os;
	};
}
