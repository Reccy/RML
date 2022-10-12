#pragma once

#include "tuple4.h"
#include "tuple3.h"

namespace RML
{
	/// <summary>
	/// A Vector in Euclidean Space
	/// </summary>
	class Vector : public Tuple4<double> {
	public:
		/// <summary>
		/// Constructs a Vector with components 0, 0, 0
		/// Note that this has an undefined direction!
		/// </summary>
		Vector();

		/// <summary>
		/// Constructs a Vector from a tuple, by copying x, y and z components.
		/// W component is set to 0.
		/// </summary>
		/// <param name="tuple">The tuple to convert to a Vector</param>
		Vector(const Tuple4 tuple);

		/// <summary>
		/// Constructs a Vector from a tuple, by copying x, y and z components.
		/// </summary>
		/// <param name="tuple">The tuple to convert to a Vector</param>
		Vector(const Tuple3<double> tuple);

		// Allows implicit conversion of Vector to Tuple3
		operator Tuple3<double>() const;

		/// <summary>
		/// Constructs a Vector with x, y and z components
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		/// <param name="z">Z component</param>
		Vector(const double x, const double y, const double z);

		/// <summary>
		/// Constructs a Vector with x, y and z components, where z is 0
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		Vector(const double x, const double y);

		/// <summary>
		/// Creates a vector where all components are 0
		/// </summary>
		/// <returns>Zero Vector</returns>
		static Vector zero();

		/// <summary>
		/// Creates a vector where all components are 1
		/// </summary>
		/// <returns>One Vector</returns>
		static Vector one();

		/// <summary>
		/// Creates a vector pointing up along the y axis
		/// </summary>
		/// <returns>Vector pointing up</returns>
		static Vector up();

		/// <summary>
		/// Creates a vector pointing up along the -y axis
		/// </summary>
		/// <returns>Vector pointing down</returns>
		static Vector down();

		/// <summary>
		/// Creates a vector pointing right along the x axis
		/// </summary>
		/// <returns>Vector pointing right</returns>
		static Vector right();

		/// <summary>
		/// Creates a vector pointing right along the -x axis
		/// </summary>
		/// <returns>Vector pointing left</returns>
		static Vector left();

		/// <summary>
		/// Creates a vector pointing forward along the z axis
		/// </summary>
		/// <returns>Vector pointing forward</returns>
		static Vector forward();

		/// <summary>
		/// Creates a vector pointing forward along the -z axis
		/// </summary>
		/// <returns>Vector pointing backward</returns>
		static Vector backward();

		/// <summary>
		/// Performs a cross product operation and returns the result
		/// </summary>
		/// <param name="a">The first vector</param>
		/// <param name="b">The second vector</param>
		/// <returns>A vector cross product</returns>
		static Vector cross(const Vector& a, const Vector& b);

		/// <summary>
		/// Performs a dot product operation and returns the result
		/// </summary>
		/// <param name="a">The first vector</param>
		/// <param name="b">The second vector</param>
		/// <returns>A scalar dot product</returns>
		static double dot(const Vector& a, const Vector& b);

		/// <summary>
		/// Calculates the angle between two normalized vectors
		/// </summary>
		/// <param name="a">The first vector</param>
		/// <param name="b">The second vector</param>
		/// <returns>Angle in degrees</returns>
		static double angle(const Vector& a, const Vector& b);

		/// <summary>
		/// Calculates the angle between two normalized vectors in relation to an axis
		/// </summary>
		/// <param name="a">The first vector</param>
		/// <param name="b">The second vector</param>
		/// <param name="axis">The axis</param>
		/// <returns>Angle in degrees, signed</returns>
		static double signed_angle(const Vector& a, const Vector& b, const Vector& axis);

		/// <summary>
		/// Reflects the vector off the normal
		/// </summary>
		/// <param name="vector">The vector to reflect</param>
		/// <param name="normal">The normal vector</param>
		/// <returns>A vector reflecting off the normal</returns>
		static Vector reflect(const Vector& vector, const Vector& normal);

		/// <summary>
		/// Projects vector p onto direction dir
		/// </summary>
		static Vector project(const Vector& p, const Vector& dir);

		/// <summary>
		/// Calculates and returns the magnitude of the vector
		/// </summary>
		/// <returns>Magnitude of the vector</returns>
		double magnitude() const;

		/// <summary>
		/// Calculates and returns a normalized version of the vector
		/// </summary>
		/// <returns>Normalized vector</returns>
		Vector normalize();

		/// <summary>
		/// Calculates and returns a normalized version of the vector.
		/// Mutates the vector.
		/// </summary>
		/// <returns>Normalized vector</returns>
		Vector normalized() const;

		/// <summary>
		/// Any methods components close to 0 are set to 0.
		/// </summary>
		/// <returns>Copy of vector where close to 0 components are set to 0</returns>
		Vector clear_near_zero() const;
	};
}
