#include "Vector3d.h"
#include <cmath>
#include <iomanip>
#include <sstream>

namespace mot
{
	namespace matrix
	{
		const Vector3d& Vector3d::set(const double& x, const double& y, const double& z)
		{
			m_x = x;
			m_y = y;
			m_z = z;
			return *this;
		}

		const Vector3d& Vector3d::set(const Vector3d& copy)
		{
			m_x = copy.getX();
			m_y = copy.getY();
			m_z = copy.getZ();
			return *this;
		}

		const Vector3d& Vector3d::operator=(const Vector3d& other)
		{
			m_x = other.getX();
			m_y = other.getY();
			m_z = other.getZ();
			return *this;
		}

		const Vector3d Vector3d::operator-() const
		{
			return Vector3d(-m_x, -m_y, -m_z);
		}

		const Vector3d& Vector3d::operator+=(const Vector3d& other)
		{
			m_x += other.getX();
			m_y += other.getY();
			m_z += other.getZ();
			return *this;
		}

		const Vector3d& Vector3d::operator-=(const Vector3d& other)
		{
			m_x -= other.getX();
			m_y -= other.getY();
			m_z -= other.getZ();
			return *this;
		}

		const Vector3d& Vector3d::operator*=(const double& other)
		{
			m_x *= other;
			m_y *= other;
			m_z *= other;
			return *this;
		}

		const Vector3d& Vector3d::operator/=(const double& other)
		{
			m_x /= other;
			m_y /= other;
			m_z /= other;
			return *this;
		}

		const double Vector3d::distance(const Vector3d& other) const
		{
			return sqrt(distanceSquared(other));
		}

		const double Vector3d::distanceSquared(const Vector3d& other) const
		{
			double xDiff, yDiff, zDiff;
			xDiff = m_x - other.getX();
			yDiff = m_y - other.getY();
			zDiff = m_z - other.getZ();
			return xDiff * xDiff + yDiff * yDiff + zDiff * zDiff;
		}

		const double Vector3d::norm() const
		{
			return sqrt(normSquared());
		}

		const double Vector3d::normSquared() const
		{
			return m_x * m_x + m_y * m_y + m_z * m_z;
		}

		const Vector3d Vector3d::normalize() const
		{
			const double norm = this->norm();
			const double inv_norm = 1.0 / norm;
			Vector3d unit = *this;
			unit.m_x *= inv_norm;
			unit.m_y *= inv_norm;
			unit.m_z *= inv_norm;
			return unit;
		}

		const string Vector3d::toString() const
		{
			using std::endl;
			using std::setw;
			using std::setprecision;
			using std::setfill;
			using std::right;
			using std::showpoint;
			using std::fixed;
			using std::stringstream;

			stringstream stream;
			stream << "( ";
			stream << fixed << setw(7) << setprecision(3) << setfill(' ') << right << showpoint << m_x;
			stream << ", ";
			stream << fixed << setw(7) << setprecision(3) << setfill(' ') << right << showpoint << m_y;
			stream << ", ";
			stream << fixed << setw(7) << setprecision(3) << setfill(' ') << right << showpoint << m_z;
			stream << " )";
			return stream.str();
		}

		const double dot(const Vector3d& vec1, const Vector3d& vec2)
		{
			return vec1.getX() * vec2.getX() + vec1.getY() * vec2.getY() + vec1.getZ() * vec2.getZ();
		}

		const Vector3d cross(const Vector3d& vec1, const Vector3d& vec2)
		{
			double x = vec1.getY() * vec2.getZ() - vec1.getZ() * vec2.getY();
			double y = vec1.getZ() * vec2.getX() - vec1.getX() * vec2.getZ();
			double z = vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX();
			return Vector3d(x, y, z);
		}

		const Vector3d getNormal(const Vector3d& vec1, const Vector3d& vec2)
		{
			Vector3d normal(cross(vec1, vec2));
			return normal.normalize();
		}


	}
}
