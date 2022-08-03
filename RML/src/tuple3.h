#pragma once

#include <iostream>
#include <type_traits>
#include "constants.h"

namespace RML
{
	/// <summary>
	/// A Tuple with x, y and z components
	/// </summary>
	template<typename T>
	class Tuple3 {
	public:
		/// <summary>
		/// Creates an empty tuple with x, y, z components
		/// </summary>
		Tuple3() : m_x(0), m_y(0), m_z(0) {}

		/// <summary>
		/// Creates a tuple with x, y, z components
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		/// <param name="z">Z component</param>
		Tuple3(const T x, const T y, const T z) : m_x(x), m_y(y), m_z(z) {}

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

		bool operator==(const Tuple3& other) const
		{
			return abs(m_x - other.m_x) < EPSILON &&
				abs(m_y - other.m_y) < EPSILON &&
				abs(m_z - other.m_z) < EPSILON;
		};

		bool operator!=(const Tuple3& other) const
		{
			return !(*this == other);
		};

		Tuple3 operator+(const Tuple3& other) const
		{
			return Tuple3(this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z);
		};

		Tuple3& operator+=(const Tuple3& other)
		{
			Tuple3 res = *this + other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			return *this;
		}

		Tuple3 operator-(const Tuple3& other) const
		{
			return Tuple3(this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z);
		};

		Tuple3& operator-=(const Tuple3& other)
		{
			Tuple3 res = *this - other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			return *this;
		}

		Tuple3 operator-() const
		{
			return Tuple3(0, 0, 0) - *this;
		};

		Tuple3 operator*(const T scalar) const
		{
			return Tuple3(this->m_x * scalar, this->m_y * scalar, this->m_z * scalar);
		};

		Tuple3& operator*=(const T scalar)
		{
			Tuple3 res = *this * scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			return *this;
		}

		Tuple3 operator/(const T scalar) const
		{
			return Tuple3(this->m_x / scalar, this->m_y / scalar, this->m_z / scalar);
		};

		Tuple3& operator/=(const T scalar)
		{
			Tuple3 res = *this / scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			this->m_z = res.m_z;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Tuple3& tuple)
		{
			os << tuple.x() << ", " << tuple.y() << ", " << tuple.z();
			return os;
		};
	protected:
		T m_x, m_y, m_z;
	};
}
