#include "gtest/gtest.h"
#include "RML.h"

namespace RML
{
	TEST(RML_Point, construct_default)
	{
		Point point = Vector();

		Point expectedPoint(0, 0, 0);

		EXPECT_EQ(point, expectedPoint);
	}

	TEST(RML_Point, construct_from_tuple)
	{
		Tuple4<double> tuple(1, 2, 3, 4);
		Point point(tuple);

		Point expectedResult(1, 2, 3);

		EXPECT_EQ(point, expectedResult);
	}

	TEST(RML_Point, x)
	{
		Point pointA(1, 2, 3);

		double expectedResult = 1;

		EXPECT_EQ(pointA.x(), expectedResult);
	}

	TEST(RML_Point, y)
	{
		Point pointA(1, 2, 3);

		double expectedResult = 2;

		EXPECT_EQ(pointA.y(), expectedResult);
	}

	TEST(RML_Point, z)
	{
		Point pointA(1, 2, 3);

		double expectedResult = 3;

		EXPECT_EQ(pointA.z(), expectedResult);
	}

	TEST(RML_Point, w_is_1)
	{
		Point pointA(1, 2, 3);

		double expectedResult = 1;

		EXPECT_EQ(pointA.w(), expectedResult);
	}

	TEST(RML_Point, equality_true)
	{
		Point point(4.3, -4.2, 3.1);
		Point expectedResult(4.3, -4.2, 3.1);
		EXPECT_TRUE(point == expectedResult);
	}

	TEST(RML_Point, equality_false)
	{
		Point point(4.3, -4.2, 3.1);
		Point expectedResult(1.0, 2.0, -9.3);
		EXPECT_FALSE(point == expectedResult);
	}

	TEST(RML_Point, inequality_true)
	{
		Point point(4.3, -4.2, 3.1);
		Point expectedResult(1.0, 2.0, -9.3);
		EXPECT_TRUE(point != expectedResult);
	}

	TEST(RML_Point, inequality_false)
	{
		Point point(4.3, -4.2, 3.1);
		Point expectedResult(4.3, -4.2, 3.1);
		EXPECT_FALSE(point != expectedResult);
	}

	TEST(RML_Point, adding_two_points_returns_a_tuple)
	{
		Point pointA(3, -2, 5);
		Point pointB(-2, 3, 1);
		Tuple4<double> expectedResult(1, 1, 6, 2);

		EXPECT_EQ((pointA + pointB), expectedResult);
	}

	TEST(RML_Point, subtracting_two_points_is_a_vector)
	{
		Point pointA(3, -2, 5);
		Point pointB(-2, 3, 1);
		Vector expectedResult(5, -5, 4);

		EXPECT_EQ((pointA - pointB).magnitude(), expectedResult.magnitude());
		EXPECT_EQ((pointA - pointB), expectedResult);
	}

	TEST(RML_Point, subtracting_vector_from_point_is_a_point)
	{
		Point point(3, 2, 1);
		Vector vector(5, 6, 7);
		Point expectedResult(-2, -4, -6);

		EXPECT_EQ((point - vector), expectedResult);
	}

	TEST(RML_Point, unary_negation_will_negate_and_transform_into_tuple)
	{
		Point point(1, -2, 3);
		Tuple4<double> expectedResult(-1, 2, -3, -1);

		EXPECT_EQ(-point, expectedResult);
	}

	TEST(RML_Point, multiplication_by_scalar_and_transform_into_tuple)
	{
		Point point(1, -2, 3);
		Tuple4<double> expectedResult(3.5, -7, 10.5, 3.5);

		EXPECT_EQ(point * 3.5, expectedResult);
	}

	TEST(RML_Point, multiplication_by_fraction_and_transform_into_tuple)
	{
		Point point(1, -2, 3);
		Tuple4<double> expectedResult(0.5, -1, 1.5, 0.5);

		EXPECT_EQ(point * 0.5, expectedResult);
	}

	TEST(RML_Point, dividing_by_scalar_and_transform_into_tuple)
	{
		Point point(1, -2, 3);
		Tuple4<double> expectedResult(0.5, -1, 1.5, 0.5);

		EXPECT_EQ(point / 2, expectedResult);
	}

	TEST(RML_Point, ostream_will_show_x_y_z_w_components)
	{
		Point tuple(4.3, -4.2, 3.1);
		std::stringstream ss;
		ss << tuple;

		EXPECT_EQ(ss.str(), "4.3, -4.2, 3.1, 1");
	}
}
