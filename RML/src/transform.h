#pragma once

#include <stack>
#include "matrix.h"
#include "tuple3.h"

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
		/// Transposes the matrix
		/// </summary>
		/// <returns>The Transform after being transposed</returns>
		const Matrix<double, 4, 4> get_transposed();

		/// <summary>
		/// Inverts the Transform
		/// </summary>
		/// <returns>The Transform after being inverted</returns>
		const Matrix<double, 4, 4> get_inverted();

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
	private:
		Tuple3<double> m_translation;
		Matrix<double, 4, 4> m_rotation;
		Tuple3<double> m_scale;
	};
}
