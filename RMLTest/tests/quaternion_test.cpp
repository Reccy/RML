#include <gtest/gtest.h>
#include "RML.h"

namespace RML
{
	TEST(RML_Quaternion, construct_quaternion_with_variables)
	{
		Quaternion q(1, 2, 3, 4);

		EXPECT_EQ(q.w(), 1);
		EXPECT_EQ(q.i(), 2);
		EXPECT_EQ(q.j(), 3);
		EXPECT_EQ(q.k(), 4);
	}

	TEST(RML_Quaternion, invert)
	{
		Quaternion q(1, 2, 3, 4);

		Quaternion i = q.inverse();

		EXPECT_EQ(i.w(), 1);
		EXPECT_EQ(i.i(), -2);
		EXPECT_EQ(i.j(), -3);
		EXPECT_EQ(i.k(), -4);
	}

	TEST(RML_Quaternion, identity)
	{
		Quaternion q = Quaternion::identity();

		EXPECT_EQ(q.w(), 1);
		EXPECT_EQ(q.i(), 0);
		EXPECT_EQ(q.j(), 0);
		EXPECT_EQ(q.k(), 0);
	}

	TEST(RML_Quaternion, euler_angles_i)
	{
		Quaternion q = Quaternion::euler_angles(90, 0, 0);

		EXPECT_TRUE(abs(q.w() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.i() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.j() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.k() - 0) < EPSILON);
	}

	TEST(RML_Quaternion, euler_angles_j)
	{
		Quaternion q = Quaternion::euler_angles(0, 90, 0);

		EXPECT_TRUE(abs(q.w() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.i() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.j() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.k() - 0) < EPSILON);
	}

	TEST(RML_Quaternion, euler_angles_k)
	{
		Quaternion q = Quaternion::euler_angles(0, 0, 90);

		EXPECT_TRUE(abs(q.w() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.i() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.j() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.k() - 0.707107) < EPSILON);
	}

	TEST(RML_Quaternion, angle_axis)
	{
		Quaternion q = Quaternion::angle_axis(90, { 1, 0, 0 });

		EXPECT_TRUE(abs(q.w() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.i() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.j() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.k() - 0) < EPSILON);
	}

	TEST(RML_Quaternion, from_to)
	{
		Vector forward = Vector::forward();
		Vector right = Vector::right();

		Quaternion q = Quaternion::from_to(forward, right);

		EXPECT_TRUE(abs(q.w() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.i() - 0) < EPSILON);
		EXPECT_TRUE(abs(q.j() - 0.707107) < EPSILON);
		EXPECT_TRUE(abs(q.k() - 0) < EPSILON);
	}

	TEST(RML_Quaternion, normalized)
	{
		Quaternion q(25, 25, 25, 25);

		Quaternion normalized = q.normalized();

		Quaternion expectedResult(0.5, 0.5, 0.5, 0.5);

		EXPECT_EQ(normalized, expectedResult);
	}

	TEST(RML_Quaternion, normalize)
	{
		Quaternion q(1, 0, 1, 0);

		q.normalize();

		Quaternion expectedResult(1/sqrt(2), 0, 1/sqrt(2), 0);

		EXPECT_EQ(q, expectedResult);
	}

	TEST(RML_Quaternion, matrix_identity)
	{
		Quaternion q = Quaternion::identity();

		Matrix<double, 4, 4> result = q.matrix();
		Matrix<double, 4, 4> expectedResult = Matrix<double, 4, 4>::identity();

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, matrix_euler)
	{
		Quaternion q = Quaternion::euler_angles(90, 0, 0);

		Matrix<double, 4, 4> result = q.matrix();
		Matrix<double, 4, 4> expectedResult = Matrix<double, 4, 4>({
			1, 0, 0, 0,
			0, 0, -1, 0,
			0, 1, 0, 0,
			0, 0, 0, 1
		});

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, multiply_with_tuple_test_1)
	{
		Quaternion q = Quaternion(0.71, 0, 0, -0.71).normalized();
		Point p(1, 0, 0);

		Point result = q * p;

		Point expectedResult(0, 1, 0);

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, multiply_with_tuple_test_2)
	{
		Quaternion q = Quaternion(0.71, 0.71, 0, 0).normalized();
		Point p(0, 0, 1);

		Point result = q * p;

		Point expectedResult(0, 1, 0);

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, multiply_with_tuple_test_3)
	{
		Quaternion q = Quaternion(0, -1, 0, 0).normalized();
		Point p(0, 5, 0);

		Point result = q * p;

		Point expectedResult(0, -5, 0);

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, multiply_with_tuple_test_4)
	{
		Quaternion q = Quaternion(0.71, 0, 0, 0.71).normalized();
		Point p(0.71, 0.71, 0);

		Point result = q * p;

		Point expectedResult(0.71, -0.71, 0);

		EXPECT_EQ(result, expectedResult);
	}

	TEST(RML_Quaternion, equality)
	{
		Quaternion lhs = Quaternion::identity();
		Quaternion rhs = Quaternion::identity();

		EXPECT_TRUE(lhs == rhs);
	}

	TEST(RML_Quaternion, inequality)
	{
		Quaternion lhs = Quaternion::identity();
		Quaternion rhs = Quaternion(1, 2, 3, 4);

		EXPECT_TRUE(lhs != rhs);
	}
}
