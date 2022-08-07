#pragma once

#include "gtest/gtest.h"
#include "RML.h"

namespace RML
{
	TEST(RML_Comparison, compare_exact_values_double)
	{
		double doubleA = 1.0;
		double doubleB = 1.0;
		EXPECT_TRUE(RML::equal(doubleA, doubleB));
	}

	TEST(RML_Comparison, compare_values_inside_epsilon_double)
	{
		double doubleA = 1.0;
		double doubleB = 1.000001;
		EXPECT_TRUE(RML::equal(doubleA, doubleB));
	}

	TEST(RML_Comparison, compare_values_outside_epsilon_double)
	{
		double doubleA = 1.0;
		double doubleB = 1.00001f;
		EXPECT_FALSE(RML::equal(doubleA, doubleB));
	}

	TEST(RML_Comparison, compare_exact_values_float)
	{
		float floatA = 1.0f;
		float floatB = 1.0f;
		EXPECT_TRUE(RML::equal(floatA, floatB));
	}

	TEST(RML_Comparison, compare_values_inside_epsilon_float)
	{
		float floatA = 1.0f;
		float floatB = 1.000001f;
		EXPECT_TRUE(RML::equal(floatA, floatB));
	}

	TEST(RML_Comparison, compare_values_outside_epsilon_float)
	{
		float floatA = 1.0f;
		float floatB = 1.00001f;
		EXPECT_FALSE(RML::equal(floatA, floatB));
	}

	TEST(RML_Comparison, compare_infinity)
	{
		using RML::INF;

		EXPECT_TRUE(RML::equal(INF, INF));
		EXPECT_TRUE(RML::equal(-INF, -INF));
		EXPECT_FALSE(RML::equal(-INF, INF));
		EXPECT_FALSE(RML::equal(INF, -INF));
		EXPECT_FALSE(RML::equal(INF, 245123.123));
	}
}
