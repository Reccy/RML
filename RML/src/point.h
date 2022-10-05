#pragma once

#include "vector.h"
#include "tuple4.h"

namespace RML
{
	/// <summary>
	/// Point in Euclidean Space
	/// </summary>
	class Point : public Tuple4<double>
	{
	public:
		/// <summary>
		/// Constructs a Point at position 0, 0, 0
		/// </summary>
		Point();

		/// <summary>
		/// Constructs a Point from a tuple, by copying x, y and z components.
		/// W component is set to 1.
		/// </summary>
		/// <param name="tuple">The tuple to convert to a Point</param>
		Point(const Tuple4 tuple);

		/// <summary>
		/// Constructs a Point with x, y and z components
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		/// <param name="z">Z component</param>
		Point(const double x, const double y, const double z);

		Vector operator-(const Point& other) const;
		Point operator-(const Vector& other) const;
		Tuple4<double> operator-() const;

		operator Tuple3<double>() const;
	};

	std::ostream& operator<<(std::ostream& os, const Point& p);
}
