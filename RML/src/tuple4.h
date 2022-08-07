#pragma once

#include <iostream>
#include <type_traits>
#include "constants.h"

namespace RML
{
	/// <summary>
	/// A Tuple with x, y, z and w components
	/// </summary>
	template<typename T>
	class Tuple4 {
	public:
		/// <summary>
		/// Creates an empty tuple with x, y, z and w components
		/// </summary>
		Tuple4() : m_x(0), m_y(0), m_z(0), m_w(0) {}

		/// <summary>
		/// Creates a tuple with x, y, z and w components
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		/// <param name="z">Z component</param>
		/// <param name="w">W component. 1 is a point, 2 is a tuple</param>
		Tuple4(const T x, const T y, const T z, const T w) : m_x(x), m_y(y), m_z(z), m_w(w) {}

		/// <summary>
		/// Returns a const X component
		/// </summary>
		inline T x() const
		{
			return this->m_x;
		};

		/// <summary>
		/// Returns a const Y component
		/// </summary>
		inline T y() const
		{
			return this->m_y;
		};

		/// <summary>
		/// Returns a const Z component
		/// </summary>
		inline T z() const
		{
			return this->m_z;
		};

		/// <summary>
		/// Returns a const W component
		/// </summary>
		inline T w() const
		{
			return this->m_w;
		};

		bool operator==(const Tuple4& other) const
		{
			return equal(m_x, other.m_x) &&
				equal(m_y, other.m_y) &&
				equal(m_z, other.m_z) &&
				equal(m_w, other.m_w);
		};

		bool operator!=(const Tuple4& other) const
		{
			return !(*this == other);
		};

		Tuple4 operator+(const Tuple4& other) const
		{
			return Tuple4(this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z, this->m_w + other.m_w);
		};

		Tuple4& operator+=(const Tuple4& other)
		{
			Tuple4 res = *this + other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			this->m_w = res.m_w;
			return *this;
		}

		Tuple4 operator-(const Tuple4& other) const
		{
			return Tuple4(this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z, this->m_w - other.m_w);
		};

		Tuple4& operator-=(const Tuple4& other)
		{
			Tuple4 res = *this - other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			this->m_w = res.m_w;
			return *this;
		}

		Tuple4 operator-() const
		{
			return Tuple4(0, 0, 0, 0) - *this;
		};

		Tuple4 operator*(const T scalar) const
		{
			return Tuple4(this->m_x * scalar, this->m_y * scalar, this->m_z * scalar, this->m_w * scalar);
		};

		Tuple4& operator*=(const T scalar)
		{
			Tuple4 res = *this * scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			this->m_w = res.m_w;
			return *this;
		}

		Tuple4 operator/(const T scalar) const
		{
			return Tuple4(this->m_x / scalar, this->m_y / scalar, this->m_z / scalar, this->m_w / scalar);
		};

		Tuple4& operator/=(const T scalar)
		{
			Tuple4 res = *this / scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			this->m_w = res.m_w;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Tuple4& tuple)
		{
			os << tuple.x() << ", " << tuple.y() << ", " << tuple.z() << ", " << tuple.w();
			return os;
		};
	protected:
		T m_x, m_y, m_z, m_w;
	};
}
