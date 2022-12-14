#include "point.h"

namespace RML
{
	Point::Point() : Tuple4(0, 0, 0, 1) {};

	Point::Point(const Tuple4 tuple) : Tuple4(tuple.x(), tuple.y(), tuple.z(), 1) {};

	Point::Point(const double x, const double y, const double z) : Tuple4(x, y, z, 1) {};

	Vector Point::operator-(const Point& other) const
	{
		return Vector(Tuple4::operator-(other));
	}

	Point Point::operator-(const Vector& other) const
	{
		return Point(Tuple4::operator-(other));
	}

	Tuple4<double> Point::operator-() const
	{
		return Tuple4::operator-();
	}

	Point::operator Tuple3<double>() const
	{
		return RML::Tuple3<double>(m_x, m_y, m_z);
	}

	std::ostream& operator<<(std::ostream& os, const Point& p)
	{
		os << p.x() << ", " << p.y() << ", " << p.z() << ", " << p.w();
		return os;
	};
}
