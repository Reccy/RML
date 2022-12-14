#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Vector, construct_default)
	{
		Vector vector = Vector();

		Vector expectedResult(0, 0, 0);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, construct_2d)
	{
		Vector vector = Vector(1, 2);

		Vector expectedResult = Vector(1, 2, 0);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, construct_from_tuple2)
	{
		Tuple4<double> tuple(1, 2, 3, 4);
		Vector vector(tuple);

		Vector expectedResult(1, 2, 3);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, construct_from_tuple3)
	{
		Tuple3<double> tuple(1, 2, 3);
		Vector vector(tuple);

		Vector expectedResult(1, 2, 3);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, implicit_tuple3)
	{
		Vector vector(1, 2, 3);
		Tuple3<double> tuple(vector);

		Vector expectedResult(tuple);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, zero_will_build_zero_vector)
	{
		Vector vector = Vector::zero();
		Vector expectedResult(0, 0, 0);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, up_will_build_vector_pointing_up)
	{
		Vector vector = Vector::up();
		Vector expectedResult(0, 1, 0);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, right_will_build_vector_pointing_right)
	{
		Vector vector = Vector::right();
		Vector expectedResult(1, 0, 0);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, forward_will_build_vector_pointing_forward)
	{
		Vector vector = Vector::forward();
		Vector expectedResult(0, 0, 1);

		EXPECT_EQ(vector, expectedResult);
	}

	TEST(RML_Vector, x)
	{
		Vector vectorA(1, 2, 3);

		double expectedResult = 1;

		EXPECT_EQ(vectorA.x(), expectedResult);
	}

	TEST(RML_Vector, y)
	{
		Vector vectorA(1, 2, 3);

		double expectedResult = 2;

		EXPECT_EQ(vectorA.y(), expectedResult);
	}

	TEST(RML_Vector, z)
	{
		Vector vectorA(1, 2, 3);

		double expectedResult = 3;

		EXPECT_EQ(vectorA.z(), expectedResult);
	}

	TEST(RML_Vector, w_is_0)
	{
		Vector vectorA(1, 2, 3);

		double expectedResult = 0;

		EXPECT_EQ(vectorA.w(), expectedResult);
	}

	TEST(RML_Vector, cross_product_a_b)
	{
		Vector vectorA(1, 2, 3);
		Vector vectorB(2, 3, 4);

		Vector expectedResult(-1, 2, -1);

		EXPECT_EQ(Vector::cross(vectorA, vectorB), expectedResult);
	}

	TEST(RML_Vector, cross_product_b_a)
	{
		Vector vectorA(1, 2, 3);
		Vector vectorB(2, 3, 4);

		Vector expectedResult(1, -2, 1);

		EXPECT_EQ(Vector::cross(vectorB, vectorA), expectedResult);
	}

	TEST(RML_Vector, dot_product)
	{
		Vector vectorA(1, 2, 3);
		Vector vectorB(2, 3, 4);

		double actual = Vector::dot(vectorA, vectorB);
		double expectedResult = 20;

		EXPECT_EQ(actual, expectedResult);
	}

	TEST(RML_Vector, angle)
	{
		Vector vectorA(1, 0, 0);
		Vector vectorB(0, 1, 0);

		double actual = Vector::angle(vectorA, vectorB);
		double expectedResult = 90;

		EXPECT_EQ(actual, expectedResult);
	}

	TEST(RML_Vector, angle_same)
	{
		Vector vectorA(1, 0, 0);
		Vector vectorB(1, 0, 0);

		double actual = Vector::angle(vectorA, vectorB);
		double expectedResult = 0;

		EXPECT_EQ(actual, expectedResult);
	}

	TEST(RML_Vector, angle_180)
	{
		Vector vectorA(1, 0, 0);
		Vector vectorB(-1, 0, 0);

		double actual = Vector::angle(vectorA, vectorB);
		double expectedResult = 180;

		EXPECT_EQ(actual, expectedResult);
	}

	TEST(RML_Vector, vector_reflection_at_45_degrees)
	{
		Vector vector(1, -1, 0);
		Vector normal(0, 1, 0);

		Vector reflected = Vector::reflect(vector, normal);
		Vector expectedResult(1, 1, 0);

		EXPECT_EQ(reflected, expectedResult);
	}

	TEST(RML_Vector, vector_reflection_off_slanted_surface)
	{
		Vector vector(0, -1, 0);
		Vector normal(sqrt(2) / 2, sqrt(2) / 2, 0);

		Vector reflected = Vector::reflect(vector, normal);
		Vector expectedResult(1, 0, 0);

		EXPECT_EQ(reflected, expectedResult);
	}

	TEST(RML_Vector, magnitude_of_vector_1_0_0)
	{
		Vector vector(1, 0, 0);
		double expectedResult = 1;

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, magnitude_of_vector_0_1_0)
	{
		Vector vector(0, 1, 0);
		double expectedResult = 1;

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, magnitude_of_vector_0_0_1)
	{
		Vector vector(0, 0, 1);
		double expectedResult = 1;

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, magnitude_of_vector_1_2_3)
	{
		Vector vector(1, 2, 3);
		double expectedResult = 3.7416573867739413; // sqrt(14)

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, magnitude_of_vector_neg1_neg2_neg3)
	{
		Vector vector(-1, -2, -3);
		double expectedResult = 3.7416573867739413; // sqrt(14)

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, normalization_of_vector_4_0_0)
	{
		Vector vector(4, 0, 0);
		Vector expectedResult(1, 0, 0);

		EXPECT_EQ(vector.normalize(), expectedResult);
	}

	TEST(RML_Vector, normalization_of_vector_1_2_3)
	{
		Vector vector(1, 2, 3);
		Vector expectedResult(0.267261f, 0.534522f, 0.801784f);

		EXPECT_EQ(vector.normalize(), expectedResult);
	}

	TEST(RML_Vector, magnitude_of_normalized_vector)
	{
		Vector vector(1, 2, 3);
		double expectedResult = 1.0;

		vector = vector.normalize();

		EXPECT_EQ(vector.magnitude(), expectedResult);
	}

	TEST(RML_Vector, equality_true)
	{
		Vector vector(4.3, -4.2, 3.1);
		Vector expectedResult(4.3, -4.2, 3.1);
		EXPECT_TRUE(vector == expectedResult);
	}

	TEST(RML_Vector, equality_false)
	{
		Vector vector(4.3, -4.2, 3.1);
		Vector expectedResult(1.0, 2.0, -9.3);
		EXPECT_FALSE(vector == expectedResult);
	}

	TEST(RML_Vector, inequality_true)
	{
		Vector vector(4.3, -4.2, 3.1);
		Vector expectedResult(1.0, 2.0, -9.3);
		EXPECT_TRUE(vector != expectedResult);
	}

	TEST(RML_Vector, inequality_false)
	{
		Vector vector(4.3, -4.2, 3.1);
		Vector expectedResult(4.3, -4.2, 3.1);
		EXPECT_FALSE(vector != expectedResult);
	}

	TEST(RML_Vector, addition_with_vectors)
	{
		Vector vectorA(3, -2, 5);
		Vector vectorB(-2, 3, 1);
		Vector expectedResult(1, 1, 6);

		EXPECT_EQ((vectorA + vectorB), expectedResult);
	}

	TEST(RML_Vector, subtracting_two_vectors_is_a_vector)
	{
		Vector vectorA(3, 2, 1);
		Vector vectorB(5, 6, 7);
		Vector expectedResult(-2, -4, -6);

		EXPECT_EQ((vectorA - vectorB), expectedResult);
	}

	TEST(RML_Vector, subtracting_a_vector_from_zero_vector_results_in_negation)
	{
		Vector zero = Vector::zero();
		Vector vector(1, -2, 3);
		Vector expectedResult(-1, 2, -3);

		EXPECT_EQ((zero - vector), expectedResult);
	}

	TEST(RML_Vector, unary_negation_will_negate_vector)
	{
		Vector vector(1, -2, 3);
		Vector expectedResult(-1, 2, -3);

		EXPECT_EQ(-vector, expectedResult);
	}

	TEST(RML_Vector, multiplication_by_scalar)
	{
		Vector tuple(1, -2, 3);
		Vector expectedResult(3.5, -7, 10.5);

		EXPECT_EQ(tuple * 3.5, expectedResult);
	}

	TEST(RML_Vector, multiplication_by_fraction)
	{
		Vector tuple(1, -2, 3);
		Vector expectedResult(0.5, -1, 1.5);

		EXPECT_EQ(tuple * 0.5, expectedResult);
	}

	TEST(RML_Vector, dividing_by_scalar)
	{
		Vector tuple(1, -2, 3);
		Vector expectedResult(0.5, -1, 1.5);

		EXPECT_EQ(tuple / 2, expectedResult);
	}

	TEST(RML_Vector, ostream_will_show_x_y_z_w_components)
	{
		Vector vector(4.3, -4.2, 3.1);
		std::stringstream ss;
		ss << vector;

		EXPECT_EQ(ss.str(), "4.3, -4.2, 3.1, 0");
	}
}
