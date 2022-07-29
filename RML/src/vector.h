#pragma once

namespace RML
{
	template<typename T>
	struct Vector4 {
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
		union { T w, a; };
	};

	template<typename T>
	struct Vector3 {
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
	};

	template<typename T>
	struct Vector2 {
		union { T x, r; };
		union { T y, g; };
	};

	template<typename T>
	struct Vector1 {
		union { T x, r; };
	};
}
