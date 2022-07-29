#include "pch.h"
#include <RML.h>

TEST(Vector4, RGBA_IS_XYZW)
{
	RML::Vector4<int> vec4 { 1, 2, 3, 4 };

	EXPECT_EQ(vec4.x, 1);
	EXPECT_EQ(vec4.y, 2);
	EXPECT_EQ(vec4.z, 3);
	EXPECT_EQ(vec4.w, 4);

	EXPECT_EQ(vec4.r, 1);
	EXPECT_EQ(vec4.g, 2);
	EXPECT_EQ(vec4.b, 3);
	EXPECT_EQ(vec4.a, 4);
}

TEST(Vector3, RGB_IS_XYZ)
{
	RML::Vector3<int> vec3{ 1, 2, 3 };

	EXPECT_EQ(vec3.x, 1);
	EXPECT_EQ(vec3.y, 2);
	EXPECT_EQ(vec3.z, 3);

	EXPECT_EQ(vec3.r, 1);
	EXPECT_EQ(vec3.g, 2);
	EXPECT_EQ(vec3.b, 3);
}

TEST(Vector2, RG_IS_XY)
{
	RML::Vector2<int> vec2{ 1,2 };

	EXPECT_EQ(vec2.x, 1);
	EXPECT_EQ(vec2.y, 2);

	EXPECT_EQ(vec2.r, 1);
	EXPECT_EQ(vec2.g, 2);
}

TEST(Vector1, R_IS_X)
{
	RML::Vector1<int> vec1{ 1 };

	EXPECT_EQ(vec1.x, 1);

	EXPECT_EQ(vec1.r, 1);
}
