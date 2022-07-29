#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Tuple4, default_constructor)
	{
		Tuple4<double> tuple;

		EXPECT_EQ(tuple.x(), 0);
		EXPECT_EQ(tuple.y(), 0);
		EXPECT_EQ(tuple.z(), 0);
		EXPECT_EQ(tuple.w(), 0);
	}

	TEST(RML_Tuple4, x)
	{
		Tuple4<double> tuple(1.0, 2.0, 3.0, 4.0);

		double expectedResult = 1.0;

		EXPECT_EQ(tuple.x(), expectedResult);
	}

	TEST(RML_Tuple4, y)
	{
		Tuple4<double> tuple(1.0, 2.0, 3.0, 4.0);

		double expectedResult = 2.0;

		EXPECT_EQ(tuple.y(), expectedResult);
	}

	TEST(RML_Tuple4, z)
	{
		Tuple4<double> tuple(1.0, 2.0, 3.0, 4.0);

		double expectedResult = 3.0;

		EXPECT_EQ(tuple.z(), expectedResult);
	}

	TEST(RML_Tuple4, w)
	{
		Tuple4<double> tuple(1.0, 2.0, 3.0, 4.0);

		double expectedResult = 4.0;

		EXPECT_EQ(tuple.w(), expectedResult);
	}

	TEST(RML_Tuple4, equality_true_double)
	{
		Tuple4<double> tuple(4.3, -4.2, 3.1, 1.0);
		Tuple4<double> expectedResult(4.3, -4.2, 3.1, 1.0);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, equality_false_double)
	{
		Tuple4<double> tuple(4.3, -4.2, 3.1, 1.0);
		Tuple4<double> expectedResult(1.0, 2.0, -9.3, 0.0);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, inequality_true_double)
	{
		Tuple4<double> tuple(4.3, -4.2, 3.1, 1.0);
		Tuple4<double> expectedResult(1.0, 2.0, -9.3, 0.0);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, inequality_false_double)
	{
		Tuple4<double> tuple(4.3, -4.2, 3.1, 1.0);
		Tuple4<double> expectedResult(4.3, -4.2, 3.1, 1.0);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, equality_true_float)
	{
		Tuple4<float> tuple(4.3f, -4.2f, 3.1f, 1.0f);
		Tuple4<float> expectedResult(4.3f, -4.2f, 3.1f, 1.0f);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, equality_false_float)
	{
		Tuple4<float> tuple(4.3f, -4.2f, 3.1f, 1.0f);
		Tuple4<float> expectedResult(1.0f, 2.0f, -9.3f, 0.0f);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, inequality_true_float)
	{
		Tuple4<float> tuple(4.3f, -4.2f, 3.1f, 1.0f);
		Tuple4<float> expectedResult(1.0f, 2.0f, -9.3f, 0.0f);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, inequality_false_float)
	{
		Tuple4<float> tuple(4.3f, -4.2f, 3.1f, 1.0f);
		Tuple4<float> expectedResult(4.3f, -4.2f, 3.1f, 1.0f);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, equality_true_int)
	{
		Tuple4<int> tuple(4, -4, 3, 1);
		Tuple4<int> expectedResult(4, -4, 3, 1);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, equality_false_int)
	{
		Tuple4<int> tuple(4, -4, 3, 1);
		Tuple4<int> expectedResult(1, 2, -9, 0);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple4, inequality_true_int)
	{
		Tuple4<int> tuple(4, -4, 3, 1);
		Tuple4<int> expectedResult(1, 2, -9, 0);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, inequality_false_int)
	{
		Tuple4<int> tuple(4, -4, 3, 1);
		Tuple4<int> expectedResult(4, -4, 3, 1);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple4, addition)
	{
		Tuple4<double> tupleA(3, -2, 5, 1);
		Tuple4<double> tupleB(-2, 3, 1, 0);
		Tuple4<double> expectedResult(1, 1, 6, 1);

		EXPECT_EQ((tupleA + tupleB), expectedResult);
	}

	TEST(RML_Tuple4, addition_compound)
	{
		Tuple4<double> tupleA(3, -2, 5, 1);
		Tuple4<double> tupleB(-2, 3, 1, 0);
		Tuple4<double> expectedResult(1, 1, 6, 1);

		tupleA += tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple4, subtraction)
	{
		Tuple4<double> tupleA(3, -2, 5, 1);
		Tuple4<double> tupleB(-2, 3, 1, 0);
		Tuple4<double> expectedResult(5, -5, 4, 1);

		EXPECT_EQ((tupleA - tupleB), expectedResult);
	}

	TEST(RML_Tuple4, subtraction_compound)
	{
		Tuple4<double> tupleA(3, -2, 5, 1);
		Tuple4<double> tupleB(-2, 3, 1, 0);
		Tuple4<double> expectedResult(5, -5, 4, 1);

		tupleA -= tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple4, unary_negation_will_negate_tuple)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(-1, 2, -3, 4);

		EXPECT_EQ(-tuple, expectedResult);
	}

	TEST(RML_Tuple4, multiplication_by_scalar)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(3.5, -7, 10.5, -14);

		EXPECT_EQ(tuple * 3.5, expectedResult);
	}

	TEST(RML_Tuple4, multiplication_by_scalar_compound)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(3.5, -7, 10.5, -14);

		tuple *= 3.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple4, multiplication_by_fraction)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(0.5, -1, 1.5, -2);

		EXPECT_EQ(tuple * 0.5, expectedResult);
	}

	TEST(RML_Tuple4, multiplication_by_fraction_compound)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(0.5, -1, 1.5, -2);

		tuple *= 0.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple4, dividing_by_scalar)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(0.5, -1, 1.5, -2);

		EXPECT_EQ(tuple / 2, expectedResult);
	}

	TEST(RML_Tuple4, dividing_by_scalar_compound)
	{
		Tuple4<double> tuple(1, -2, 3, -4);
		Tuple4<double> expectedResult(0.5, -1, 1.5, -2);

		tuple /= 2;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple4, ostream_will_show_x_y_z_w_components)
	{
		Tuple4<double> tuple(4.3, -4.2, 3.1, 1.0);
		std::stringstream ss;
		ss << tuple;

		EXPECT_EQ(ss.str(), "4.3, -4.2, 3.1, 1");
	}
}
