#include "transform.h"
#include "trig.h"
#include <vector>

namespace RML
{
	Transform::Transform() :
		position(),
		rotation(Quaternion::identity()),
		scaling(1, 1, 1) {};

	Transform::Transform(Matrix<double, 4, 4> matrix) :
		position(),
		rotation(Quaternion::identity()),
		scaling(1, 1, 1)
	{
		double posX = matrix(0, 3);
		double posY = matrix(1, 3);
		double posZ = matrix(2, 3);

		position = Vector(posX, posY, posZ);

		double scaleX = Vector(matrix(0,0), matrix(1,0), matrix(2,0)).magnitude();
		double scaleY = Vector(matrix(0,1), matrix(1,1), matrix(2,1)).magnitude();
		double scaleZ = Vector(matrix(0,2), matrix(1,2), matrix(2,2)).magnitude();

		scaling = Vector(scaleX, scaleY, scaleZ);

		double rotA = matrix(0,0) / scaleX;
		double rotB = matrix(0,1) / scaleY;
		double rotC = matrix(0,2) / scaleZ;

		double rotD = matrix(1,0) / scaleX;
		double rotE = matrix(1,1) / scaleY;
		double rotF = matrix(1,2) / scaleZ;

		double rotG = matrix(2,0) / scaleX;
		double rotH = matrix(2,1) / scaleY;
		double rotI = matrix(2,2) / scaleZ;

		Matrix<double, 4, 4> rotMatrix({
			rotA, rotB, rotC, 0,
			rotD, rotE, rotF, 0,
			rotG, rotH, rotI, 0,
			0,    0,    0,    1
		});

		rotation = Quaternion(rotMatrix);
	}

	Vector Transform::up() const { return rotation * Vector::up(); }
	Vector Transform::down() const { return rotation * Vector::down(); }
	Vector Transform::left() const { return rotation * Vector::left(); }
	Vector Transform::right() const { return rotation * Vector::right(); }
	Vector Transform::forward() const { return rotation * Vector::forward(); }
	Vector Transform::backward() const { return rotation * Vector::backward(); }

	Transform& Transform::translate(const double x, const double y, const double z)
	{
		position = Tuple3<double>(position) + Tuple3<double>(x, y, z);
		return *this;
	}

	Transform& Transform::rotate(const double xDeg, const double yDeg, const double zDeg)
	{
		rotation = rotation * Quaternion::euler_angles(xDeg, yDeg, zDeg);
		return *this;
	}

	Transform& Transform::scale(const double x, const double y, const double z)
	{
		scaling = { x * scaling.x(), y * scaling.y(), z * scaling.z() };
		return *this;
	}

	void Transform::look_at(RML::Point target)
	{
		look_at(target, RML::Vector::forward());
	}

	void Transform::look_at(RML::Point target, RML::Vector up)
	{
		RML::Vector dirToTarget = RML::Vector(target - position).normalized();

		RML::Quaternion fromToRot = RML::Quaternion::from_to(up, dirToTarget);

		RML::Vector actualVec = fromToRot * RML::Vector::forward();

		rotation = fromToRot;
	}

	void Transform::rotate_around(RML::Vector origin, RML::Vector axisDirection, double angleDegrees)
	{
		
	}

	const Matrix<double, 4, 4> Transform::get_transposed() const
	{
		return matrix().transpose();
	}

	const Matrix<double, 4, 4> Transform::get_inverted() const
	{
		return matrix().invert();
	}

	const Matrix<double, 4, 4> Transform::matrix() const
	{
		Matrix<double, 4, 4> tMatrix({
			1, 0, 0, position.x(),
			0, 1, 0, position.y(),
			0, 0, 1, position.z(),
			0, 0, 0, 1
		});

		Matrix<double, 4, 4> rMatrix = rotation.matrix();

		Matrix<double, 4, 4> sMatrix({
			scaling.x(), 0,           0,           0,
			0,           scaling.y(), 0,           0,
			0,           0,           scaling.z(), 0,
			0,           0,           0,           1
		});

		auto result = tMatrix * rMatrix * sMatrix;
		return result;
	}

	Tuple4<double> Transform::operator*(const Tuple4<double>& tuple) const
	{
		return matrix() * tuple;
	}

	bool Transform::operator==(const Transform& other) const
	{
		return matrix() == other.matrix();
	}

	bool Transform::operator!=(const Transform& other) const
	{
		return !((*this) == other);
	}
}
