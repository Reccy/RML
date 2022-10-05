#pragma once

#include <stack>
#include "matrix.h"
#include "tuple3.h"
#include "quaternion.h"

namespace RML
{
	/// <summary>
	/// Represents a Transformation Matrix that can be used to transform vectors and points
	/// </summary>
	class Transform
	{
	public:
		/// <summary>
		/// Constructs a Transform with the identity matrix
		/// </summary>
		Transform();

		/// <summary>
		/// Constructs a Transform from a matrix
		/// </summary>
		Transform(Matrix<double, 4, 4> matrix);

		Vector up() const;
		Vector down() const;
		Vector left() const;
		Vector right() const;
		Vector forward() const;
		Vector backward() const;

		/// <summary>
		/// Translates the Transform along x, y, z co-ordinates
		/// </summary>
		/// <param name="x">X translation</param>
		/// <param name="y">Y translation</param>
		/// <param name="z">Z translation</param>
		/// <returns>The Transform after being translated</returns>
		Transform& translate(const double x, const double y, const double z);

		/// <summary>
		/// Scales the Transform along x, y, z axes
		/// </summary>
		/// <param name="x">Scale along the X axis</param>
		/// <param name="y">Scale along the Y axis</param>
		/// <param name="z">Scale along the Z axis</param>
		/// <returns>The Transform after being scaled</returns>
		Transform& scale(const double x, const double y, const double z);

		/// <summary>
		/// Rotates the Transform along the x, y and z axes
		/// </summary>
		/// <param name="x">Rotate around the X axis in degrees</param>
		/// <param name="y">Rotate around the Y axis in degrees</param>
		/// <param name="z">Rotate around the Z axis in degrees</param>
		/// <returns>The Transform after being rotated</returns>
		Transform& rotate(const double xDeg, const double yDeg, const double zDeg);

		/// <summary>
		/// Rotates the transform so that its forward vector points at the target
		/// </summary>
		/// <param name="target">Position of the target</param>
		void look_at(RML::Point target);

		/// <summary>
		/// Rotates the transform so that its forward vector points at the target
		/// </summary>
		/// <param name="target">Position of the target</param>
		/// <param name="forward">Forward direction vector</param>
		void look_at(RML::Point target, RML::Vector forward);

		/// <summary>
		/// Rotates the transform around the origin point. Modifies position and rotation.
		/// </summary>
		/// <param name="origin">The point to rotate around</param>
		/// <param name="axisDirection">The direciton to rotate around</param>
		/// <param name="angleDegrees">How much to rotate in degrees</param>
		void rotate_around(RML::Vector origin, RML::Vector axisDirection, double angleDegrees);

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		/// <returns>The Matrix after being transposed</returns>
		const Matrix<double, 4, 4> get_transposed() const;

		/// <summary>
		/// Inverts the Transform
		/// </summary>
		/// <returns>The Matrix after being inverted</returns>
		const Matrix<double, 4, 4> get_inverted() const;

		/// <summary>
		/// Returns the transform as an actual matrix
		/// </summary>
		/// <returns>The transform matrix</returns>
		const Matrix<double, 4, 4> matrix() const;

		/// <summary>
		/// Multiplies the Tuple by the Transform, and returns the transformed Tuple
		/// </summary>
		/// <param name="tuple">The Tuple to transform</param>
		/// <returns>The Tuple after being transformed</returns>
		Tuple4<double> operator*(const Tuple4<double>& tuple) const;

		bool operator==(const Transform& other) const;
		bool operator!=(const Transform& other) const;
	public:
		Vector position;
		Quaternion rotation;
		Vector scaling;
	};
}
