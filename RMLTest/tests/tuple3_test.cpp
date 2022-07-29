#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Tuple3, x)
	{
		Tuple3<double> tuple(1.0, 2.0, 3.0);

		double expectedResult = 1.0;

		EXPECT_EQ(tuple.x(), expectedResult);
	}

	TEST(RML_Tuple3, y)
	{
		Tuple3<double> tuple(1.0, 2.0, 3.0);

		double expectedResult = 2.0;

		EXPECT_EQ(tuple.y(), expectedResult);
	}

	TEST(RML_Tuple3, z)
	{
		Tuple3<double> tuple(1.0, 2.0, 3.0);

		double expectedResult = 3.0;

		EXPECT_EQ(tuple.z(), expectedResult);
	}

	TEST(RML_Tuple3, equality_true_double)
	{
		Tuple3<double> tuple(4.3, -4.2, 3.1);
		Tuple3<double> expectedResult(4.3, -4.2, 3.1);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, equality_false_double)
	{
		Tuple3<double> tuple(4.3, -4.2, 3.1);
		Tuple3<double> expectedResult(1.0, 2.0, -9.3);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, inequality_true_double)
	{
		Tuple3<double> tuple(4.3, -4.2, 3.1);
		Tuple3<double> expectedResult(1.0, 2.0, -9.3);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, inequality_false_double)
	{
		Tuple3<double> tuple(4.3, -4.2, 3.1);
		Tuple3<double> expectedResult(4.3, -4.2, 3.1);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, equality_true_float)
	{
		Tuple3<float> tuple(4.3f, -4.2f, 3.1f);
		Tuple3<float> expectedResult(4.3f, -4.2f, 3.1f);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, equality_false_float)
	{
		Tuple3<float> tuple(4.3f, -4.2f, 3.1f);
		Tuple3<float> expectedResult(1.0f, 2.0f, -9.3f);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, inequality_true_float)
	{
		Tuple3<float> tuple(4.3f, -4.2f, 3.1f);
		Tuple3<float> expectedResult(1.0f, 2.0f, -9.3f);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, inequality_false_float)
	{
		Tuple3<float> tuple(4.3f, -4.2f, 3.1f);
		Tuple3<float> expectedResult(4.3f, -4.2f, 3.1f);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, equality_true_int)
	{
		Tuple3<int> tuple(4, -4, 3);
		Tuple3<int> expectedResult(4, -4, 3);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, equality_false_int)
	{
		Tuple3<int> tuple(4, -4, 3);
		Tuple3<int> expectedResult(1, 2, -9);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple3, inequality_true_int)
	{
		Tuple3<int> tuple(4, -4, 3);
		Tuple3<int> expectedResult(1, 2, -9);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, inequality_false_int)
	{
		Tuple3<int> tuple(4, -4, 3);
		Tuple3<int> expectedResult(4, -4, 3);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple3, addition)
	{
		Tuple3<double> tupleA(3, -2, 5);
		Tuple3<double> tupleB(-2, 3, 1);
		Tuple3<double> expectedResult(1, 1, 6);

		EXPECT_EQ((tupleA + tupleB), expectedResult);
	}

	TEST(RML_Tuple3, addition_compound)
	{
		Tuple3<double> tupleA(3, -2, 5);
		Tuple3<double> tupleB(-2, 3, 1);
		Tuple3<double> expectedResult(1, 1, 6);

		tupleA += tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple3, subtraction)
	{
		Tuple3<double> tupleA(3, -2, 5);
		Tuple3<double> tupleB(-2, 3, 1);
		Tuple3<double> expectedResult(5, -5, 4);

		EXPECT_EQ((tupleA - tupleB), expectedResult);
	}

	TEST(RML_Tuple3, subtraction_compound)
	{
		Tuple3<double> tupleA(3, -2, 5);
		Tuple3<double> tupleB(-2, 3, 1);
		Tuple3<double> expectedResult(5, -5, 4);

		tupleA -= tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple3, unary_negation_will_negate_tuple)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(-1, 2, -3);

		EXPECT_EQ(-tuple, expectedResult);
	}

	TEST(RML_Tuple3, multiplication_by_scalar)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(3.5, -7, 10.5);

		EXPECT_EQ(tuple * 3.5, expectedResult);
	}

	TEST(RML_Tuple3, multiplication_by_scalar_compound)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(3.5, -7, 10.5);

		tuple *= 3.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple3, multiplication_by_fraction)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(0.5, -1, 1.5);

		EXPECT_EQ(tuple * 0.5, expectedResult);
	}

	TEST(RML_Tuple3, multiplication_by_fraction_compound)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(0.5, -1, 1.5);

		tuple *= 0.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple3, dividing_by_scalar)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(0.5, -1, 1.5);

		EXPECT_EQ(tuple / 2, expectedResult);
	}

	TEST(RML_Tuple3, dividing_by_scalar_compound)
	{
		Tuple3<double> tuple(1, -2, 3);
		Tuple3<double> expectedResult(0.5, -1, 1.5);

		tuple /= 2;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple3, ostream_will_show_x_y_z_w_components)
	{
		Tuple3<double> tuple(4.3, -4.2, 3.1);
		std::stringstream ss;
		ss << tuple;

		EXPECT_EQ(ss.str(), "4.3, -4.2, 3.1");
	}
}
