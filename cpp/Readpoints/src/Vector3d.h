#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <string>

namespace mot
{
	namespace matrix
	{
		using std::string;

		struct Vector3d
		{
		private:
			double m_x;
			double m_y;
			double m_z;

		public:
			Vector3d() : m_x(0.0), m_y(0.0), m_z(0.0) {}
			Vector3d(const double& x, const double& y, const double& z) : m_x(x), m_y(y), m_z(z) {}
			Vector3d(const Vector3d& copy) : m_x(copy.m_x), m_y(copy.m_y), m_z(copy.m_z) {}
			virtual ~Vector3d() {}

		public:
			const double& getX() const { return m_x; }
			const double& getY() const { return m_y; }
			const double& getZ() const { return m_z; }
			const Vector3d& setX(const double& x) { m_x = x; }
			const Vector3d& setY(const double& y) { m_y = y; }
			const Vector3d& setZ(const double& z) { m_z = z; }
			const Vector3d& set(const double& x, const double& y, const double& z);
			const Vector3d& set(const Vector3d& copy);

		public:
			static const Vector3d zero() { return Vector3d(0.0f, 0.0f, 0.0f); }
			static const Vector3d unitX() { return Vector3d(1.0f, 0.0f, 0.0f); }
			static const Vector3d unitY() { return Vector3d(0.0f, 1.0f, 0.0f); }
			static const Vector3d unitZ() { return Vector3d(0.0f, 0.0f, 1.0f); }

		public:
			const Vector3d& operator=(const Vector3d& other);
			const Vector3d operator-() const;
			const Vector3d& operator+=(const Vector3d& other);
			const Vector3d& operator-=(const Vector3d& other);
			const Vector3d& operator*=(const double& other);
			const Vector3d& operator/=(const double& other);

		public:
			const double distance(const Vector3d& other) const;
			const double distanceSquared(const Vector3d& other) const;
			const double norm() const;
			const double normSquared() const;
			const Vector3d normalize() const;
			const string toString() const;
		};

		const double dot(const Vector3d& vec1, const Vector3d& vec2);

		const Vector3d cross(const Vector3d& vec1, const Vector3d& vec2);

		const Vector3d getNormal(const Vector3d& vec1, const Vector3d& vec2);

		inline const Vector3d operator+(const Vector3d& vec1, const Vector3d& vec2)
		{
			return Vector3d(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY(), vec1.getZ() + vec2.getZ());
		}

		inline const Vector3d operator-(const Vector3d& vec1, const Vector3d& vec2)
		{
			return Vector3d(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY(), vec1.getZ() - vec2.getZ());
		}

		inline const Vector3d operator*(const Vector3d& vec, const double& d)
		{
			return Vector3d(vec.getX() * d, vec.getY() * d, vec.getZ() * d);
		}

		inline const Vector3d operator*(const double& d, const Vector3d& vec)
		{
			return vec * d;
		}

		inline const Vector3d operator/(const Vector3d& vec, const double& d)
		{
			return Vector3d(vec.getX() / d, vec.getY() / d, vec.getZ() / d);
		}
	}
}

#endif // !VECTOR_3D_H
