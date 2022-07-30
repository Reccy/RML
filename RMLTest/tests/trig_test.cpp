#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Trig, value_of_pi)
	{
		EXPECT_EQ(Trig::PI, 3.141592653589793238462643383279502884);
	}

	TEST(RML_Trig, convert_degrees_to_radians)
	{
		double degrees = 45.0;
		double result = Trig::degrees_to_radians(degrees);

		double expectedResult = 0.785398;

		EXPECT_TRUE(abs(result) - abs(expectedResult) < EPSILON);
	}

	TEST(RML_Trig, convert_radians_to_degrees)
	{
		double radians = 0.785398;
		double result = Trig::radians_to_degrees(radians);

		double expectedResult = 45.0;

		EXPECT_TRUE(abs(result) - abs(expectedResult) < EPSILON);
	}
}
