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

	Quaternion::Quaternion(Matrix<double, 4, 4> matrix)
		: m_w(0),
		  m_i(0),
		  m_j(0),
		  m_k(0)
	{
		// Source: https://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/forum.htm

		if ((matrix(0, 0) > matrix(1, 1)) && (matrix(0, 0) > matrix(2, 2)))
		{
			double s = sqrt(1.0 + matrix(0,0) - matrix(1,1) - matrix(2,2)) * 2;
			m_i = 0.25 * s;
			m_j = (matrix(0, 1) + matrix(1, 0)) / s;
			m_k = (matrix(0, 2) - matrix(2, 0)) / s;
			m_w = (matrix(1, 2) - matrix(2, 1)) / s;
		}
		else if (matrix(1, 1) > matrix(2, 2))
		{
			double s = sqrt(1.0 + matrix(1, 1) - matrix(0, 0) - matrix(2, 2)) * 2;
			m_i = (matrix(0, 1) + matrix(1, 0)) / s;
			m_j = 0.25 * s;
			m_k = (matrix(1, 2) + matrix(2, 1)) / s;
			m_w = (matrix(0, 2) - matrix(2, 0)) / s;
		}
		else
		{
			double s = sqrt(1.0 + matrix(2, 2) - matrix(0, 0) - matrix(1, 1)) * 2;
			m_i = (matrix(0, 2) + matrix(2, 0)) / s;
			m_j = (matrix(1, 2) + matrix(2, 1)) / s;
			m_k = 0.25 * s;
			m_w = (matrix(0, 1) - matrix(1, 0)) / s;
		}
	}

	Quaternion Quaternion::identity()
	{
		return Quaternion(1, 0, 0, 0);
	}

	// Source: https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
	Quaternion Quaternion::euler_angles(double xDegrees, double yDegrees, double zDegrees)
	{
		double x = Trig::degrees_to_radians(xDegrees);
		double y = Trig::degrees_to_radians(yDegrees);
		double z = Trig::degrees_to_radians(zDegrees);

		double cx = cos(x * 0.5);
		double sx = sin(x * 0.5);

		double cy = cos(y * 0.5);
		double sy = sin(y * 0.5);

		double cz = cos(z * 0.5);
		double sz = sin(z * 0.5);

		double w = cx * cy * cz + sx * sy * sz;
		double i = sx * cy * cz - cx * sy * sz;
		double j = cx * sy * cz + sx * cy * sz;
		double k = cx * cy * sz - sx * sy * cz;

		return { w, i, j, k };
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

	Quaternion Quaternion::from_to(const Vector& fromDirection, const Vector& toDirection)
	{
		RML::Vector axis = RML::Vector::cross(fromDirection, toDirection);
		double angle = RML::Vector::angle(fromDirection, toDirection);
		
		if (angle <= EPSILON || angle >= 180 - EPSILON)
		{
			RML::Vector r = RML::Vector::cross(fromDirection, RML::Vector::right());
			axis = RML::Vector::cross(r, fromDirection);

			if (axis.magnitude() < EPSILON)
				axis = RML::Vector::up();
		}
		
		return Quaternion::angle_axis(angle, axis.normalized());
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

	// Source: https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
	Vector Quaternion::to_euler() const
	{
		RML::Vector eulerAngles;

		double x, y, z;

		// roll (x-axis rotation)
		double sinr_cosp = 2 * (m_w * m_i + m_j * m_k);
		double cosr_cosp = 1 - 2 * (m_w * m_i + m_j * m_k);
		x = std::atan2(sinr_cosp, cosr_cosp);

		// pitch (y-axis rotation)
		double sinp = 2 * (m_w * m_j - m_k * m_i);
		if (std::abs(sinp) >= 1)
			y = std::copysign(RML::Trig::PI / 2, sinp); // use 90 degrees if out of range
		else
			y = std::asin(sinp);

		// yaw (z-axis rotation)
		double siny_cosp = 2 * (m_w * m_k + m_i * m_j);
		double cosy_cosp = 1 - 2 * (m_j * m_j + m_k * m_k);
		z = std::atan2(siny_cosp, cosy_cosp);

		return {
			Trig::radians_to_degrees(x),
			Trig::radians_to_degrees(y),
			Trig::radians_to_degrees(z)
		};
	}

	Matrix<double, 4, 4> Quaternion::matrix() const
	{
		double a = 1 - 2 * (pow(m_j, 2) + pow(m_k, 2));
		double b = 2 * (m_i * m_j - m_k * m_w);
		double c = 2 * (m_i * m_k + m_j * m_w);
		double d = 2 * (m_i * m_j + m_k * m_w);
		double e = 1 - 2 * (pow(m_i, 2) + pow(m_k, 2));
		double f = 2 * (m_j * m_k - m_i * m_w);
		double g = 2 * (m_i * m_k - m_j * m_w);
		double h = 2 * (m_j * m_k + m_i * m_w);
		double i = 1 - 2 * (pow(m_i, 2) + pow(m_j, 2));

		return {{
			a, b, c, 0,
			d, e, f, 0,
			g, h, i, 0,
			0 ,0, 0, 1
		}};
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
		Quaternion p(t.w(), t.x(), t.y(), t.z());
		Quaternion r = *this * p * inverse();

		return { r.i(), r.j(), r.k(), r.w() };
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
