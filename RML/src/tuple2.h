#pragma once

#include <iostream>
#include <type_traits>
#include "constants.h"

namespace RML
{
	/// <summary>
	/// A Tuple with x and y components
	/// </summary>
	template<typename T>
	class Tuple2 {
	public:
		/// <summary>
		/// Creates an empty tuple with x, y components
		/// </summary>
		Tuple2() : m_x(0), m_y(0) {}

		/// <summary>
		/// Creates a tuple with x, y components
		/// </summary>
		/// <param name="x">X component</param>
		/// <param name="y">Y component</param>
		Tuple2(const T x, const T y) : m_x(x), m_y(y) {}

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

		bool operator==(const Tuple2& other) const
		{
			return equal(m_x, other.m_x) &&
				equal(m_y, other.m_y);
		};

		bool operator!=(const Tuple2& other) const
		{
			return !(*this == other);
		};

		Tuple2 operator+(const Tuple2& other) const
		{
			return Tuple2(this->m_x + other.m_x, this->m_y + other.m_y);
		};

		Tuple2& operator+=(const Tuple2& other)
		{
			Tuple2 res = *this + other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			return *this;
		}

		Tuple2 operator-(const Tuple2& other) const
		{
			return Tuple2(this->m_x - other.m_x, this->m_y - other.m_y);
		};

		Tuple2& operator-=(const Tuple2& other)
		{
			Tuple2 res = *this - other;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			return *this;
		}

		Tuple2 operator-() const
		{
			return Tuple2(0, 0) - *this;
		};

		Tuple2 operator*(const T scalar) const
		{
			return Tuple2(this->m_x * scalar, this->m_y * scalar);
		};

		Tuple2& operator*=(const T scalar)
		{
			Tuple2 res = *this * scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			return *this;
		}

		Tuple2 operator/(const T scalar) const
		{
			return Tuple2(this->m_x / scalar, this->m_y / scalar);
		};

		Tuple2& operator/=(const T scalar)
		{
			Tuple2 res = *this / scalar;
			this->m_x = res.m_x;
			this->m_y = res.m_y;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Tuple2& tuple)
		{
			os << tuple.x() << ", " << tuple.y();
			return os;
		};
	protected:
		T m_x, m_y;
	};
}
