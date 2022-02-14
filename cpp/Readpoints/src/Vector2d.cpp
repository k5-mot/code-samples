#include "Vector2d.h"
#include <cmath>
#include <iomanip>
#include <sstream>

namespace matrix
{
	const Vector2d& Vector2d::set(const double& x, const double& y)
	{
		m_x = x;
		m_y = y;
		return *this;
	}

	const Vector2d& Vector2d::set(const Vector2d& copy)
	{
		m_x = copy.getX();
		m_y = copy.getY();
		return *this;
	}

	const Vector2d& Vector2d::operator=(const Vector2d& other)
	{
		m_x = other.getX();
		m_y = other.getY();
		return *this;
	}

	const Vector2d Vector2d::operator-() const
	{
		return Vector2d(-m_x, -m_y);
	}

	const Vector2d& Vector2d::operator+=(const Vector2d& other)
	{
		m_x += other.m_x;
		m_y += other.m_y;
		return *this;
	}

	const Vector2d& Vector2d::operator-=(const Vector2d& other)
	{
		m_x -= other.m_x;
		m_y -= other.m_y;
		return *this;
	}

	const Vector2d& Vector2d::operator*=(const double& other)
	{
		m_x *= other;
		m_y *= other;
		return *this;
	}

	const Vector2d& Vector2d::operator/=(const double& other)
	{
		m_x /= other;
		m_y /= other;
		return *this;
	}

	const double Vector2d::distance(const Vector2d& other) const
	{
		double xDiff, yDiff;
		xDiff = m_x - other.getX();
		yDiff = m_y - other.getY();
		return sqrt(xDiff * xDiff + yDiff * yDiff);
	}

	const double Vector2d::norm() const
	{
		return sqrt(m_x * m_x + m_y * m_y);
	}

	const Vector2d& Vector2d::normalize()
	{
		const double norm = this->norm();
		const double inv_norm = 1.0 / norm;
		m_x *= inv_norm;
		m_y *= inv_norm;
		return *this;
	}

	const string Vector2d::toString() const
	{
		using std::endl;
		using std::setw;
		using std::setprecision;
		using std::setfill;
		using std::left;
		using std::showpoint;
		using std::stringstream;

		stringstream stream;
		stream << "( ";
		stream << setw(7) << setprecision(3) << setfill(' ') << left << showpoint << m_x;
		stream << ",";
		stream << setw(7) << setprecision(3) << setfill(' ') << left << showpoint << m_y;
		stream << " )";
		return stream.str();
	}

}
