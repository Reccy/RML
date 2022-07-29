#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Tuple2, default_constructor)
	{
		Tuple2<double> tuple;

		EXPECT_EQ(tuple.x(), 0);
		EXPECT_EQ(tuple.y(), 0);
	}

	TEST(RML_Tuple2, x)
	{
		Tuple2<double> tuple(1.0, 2.0);

		double expectedResult = 1.0;

		EXPECT_EQ(tuple.x(), expectedResult);
	}

	TEST(RML_Tuple2, y)
	{
		Tuple2<double> tuple(1.0, 2.0);

		double expectedResult = 2.0;

		EXPECT_EQ(tuple.y(), expectedResult);
	}

	TEST(RML_Tuple2, equality_true_double)
	{
		Tuple2<double> tuple(4.3, -4.2);
		Tuple2<double> expectedResult(4.3, -4.2);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, equality_false_double)
	{
		Tuple2<double> tuple(4.3, -4.2);
		Tuple2<double> expectedResult(1.0, 2.0);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, inequality_true_double)
	{
		Tuple2<double> tuple(4.3, -4.2);
		Tuple2<double> expectedResult(1.0, 2.0);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, inequality_false_double)
	{
		Tuple2<double> tuple(4.3, -4.2);
		Tuple2<double> expectedResult(4.3, -4.2);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, equality_true_float)
	{
		Tuple2<float> tuple(4.3f, -4.2f);
		Tuple2<float> expectedResult(4.3f, -4.2f);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, equality_false_float)
	{
		Tuple2<float> tuple(4.3f, -4.2f);
		Tuple2<float> expectedResult(1.0f, 2.0f);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, inequality_true_float)
	{
		Tuple2<float> tuple(4.3f, -4.2f);
		Tuple2<float> expectedResult(1.0f, 2.0f);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, inequality_false_float)
	{
		Tuple2<float> tuple(4.3f, -4.2f);
		Tuple2<float> expectedResult(4.3f, -4.2f);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, equality_true_int)
	{
		Tuple2<int> tuple(4, -4);
		Tuple2<int> expectedResult(4, -4);
		EXPECT_TRUE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, equality_false_int)
	{
		Tuple2<int> tuple(4, -4);
		Tuple2<int> expectedResult(1, 2);
		EXPECT_FALSE(tuple == expectedResult);
	}

	TEST(RML_Tuple2, inequality_true_int)
	{
		Tuple2<int> tuple(4, -4);
		Tuple2<int> expectedResult(1, 2);
		EXPECT_TRUE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, inequality_false_int)
	{
		Tuple2<int> tuple(4, -4);
		Tuple2<int> expectedResult(4, -4);
		EXPECT_FALSE(tuple != expectedResult);
	}

	TEST(RML_Tuple2, addition)
	{
		Tuple2<double> tupleA(3, -2);
		Tuple2<double> tupleB(-2, 3);
		Tuple2<double> expectedResult(1, 1);

		EXPECT_EQ((tupleA + tupleB), expectedResult);
	}

	TEST(RML_Tuple2, addition_compound)
	{
		Tuple2<double> tupleA(3, -2);
		Tuple2<double> tupleB(-2, 3);
		Tuple2<double> expectedResult(1, 1);

		tupleA += tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple2, subtraction)
	{
		Tuple2<double> tupleA(3, -2);
		Tuple2<double> tupleB(-2, 3);
		Tuple2<double> expectedResult(5, -5);

		EXPECT_EQ((tupleA - tupleB), expectedResult);
	}

	TEST(RML_Tuple2, subtraction_compound)
	{
		Tuple2<double> tupleA(3, -2);
		Tuple2<double> tupleB(-2, 3);
		Tuple2<double> expectedResult(5, -5);

		tupleA -= tupleB;

		EXPECT_EQ(tupleA, expectedResult);
	}

	TEST(RML_Tuple2, unary_negation_will_negate_tuple)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(-1, 2);

		EXPECT_EQ(-tuple, expectedResult);
	}

	TEST(RML_Tuple2, multiplication_by_scalar)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(3.5, -7);

		EXPECT_EQ(tuple * 3.5, expectedResult);
	}

	TEST(RML_Tuple2, multiplication_by_scalar_compound)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(3.5, -7);

		tuple *= 3.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple2, multiplication_by_fraction)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(0.5, -1);

		EXPECT_EQ(tuple * 0.5, expectedResult);
	}

	TEST(RML_Tuple2, multiplication_by_fraction_compound)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(0.5, -1);

		tuple *= 0.5;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple2, dividing_by_scalar)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(0.5, -1);

		EXPECT_EQ(tuple / 2, expectedResult);
	}

	TEST(RML_Tuple2, dividing_by_scalar_compound)
	{
		Tuple2<double> tuple(1, -2);
		Tuple2<double> expectedResult(0.5, -1);

		tuple /= 2;

		EXPECT_EQ(tuple, expectedResult);
	}

	TEST(RML_Tuple2, ostream_will_show_x_y_z_w_components)
	{
		Tuple2<double> tuple(4.3, -4.2);
		std::stringstream ss;
		ss << tuple;

		EXPECT_EQ(ss.str(), "4.3, -4.2");
	}
}
