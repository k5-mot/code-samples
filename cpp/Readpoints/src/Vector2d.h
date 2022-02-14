#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <string>


namespace matrix
{
  using std::string;

  struct Vector2d
  {
    private:
      double m_x;
      double m_y;

    public:
      Vector2d() : m_x(0.0), m_y(0.0) {}
      Vector2d(const double& x, const double& y) : m_x(x), m_y(y) {}
      Vector2d(const Vector2d& copy) : m_x(copy.m_x), m_y(copy.m_y) {}
      virtual ~Vector2d() {}

    public:
      const double& getX() const { return m_x; }
      const double& getY() const { return m_y; }
      const Vector2d& set(const double& x, const double& y);
      const Vector2d& set(const Vector2d& copy);

    public:
      static const Vector2d zero() { return Vector2d(0.0, 0.0); }
      static const Vector2d unitX() { return Vector2d(1.0, 0.0); }
      static const Vector2d unitY() { return Vector2d(0.0, 1.0); }

    public:
      const Vector2d& operator=(const Vector2d& other);
      const Vector2d  operator-() const;
      const Vector2d& operator+=(const Vector2d& other);
      const Vector2d& operator-=(const Vector2d& other);
      const Vector2d& operator*=(const double& other);
      const Vector2d& operator/=(const double& other);

    public:
      const double distance(const Vector2d& other) const;
      const double norm() const;
      const Vector2d& normalize();
      const string toString() const;
  };

  inline const Vector2d operator+(const Vector2d& vec1, const Vector2d& vec2)
  {
    return Vector2d(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY());
  }

  inline const Vector2d operator-(const Vector2d& vec1, const Vector2d& vec2)
  {
    return Vector2d(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY());
  }

  inline const Vector2d operator*(const Vector2d& vec, const double& d)
  {
    return Vector2d(vec.getX() * d, vec.getY() * d);
  }

  inline const Vector2d operator*(const double& d, const Vector2d& vec)
  {
    return vec * d;
  }

  inline const Vector2d operator/(const Vector2d& vec, const double& d)
  {
    return Vector2d(vec.getX() / d, vec.getY() / d);
  }

  inline const double dot(const Vector2d& vec1, const Vector2d& vec2)
  {
    return vec1.getX() * vec2.getX() + vec1.getY() * vec2.getY();
  }

  inline const double cross(const Vector2d& vec1, const Vector2d& vec2)
  {
    return vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX();
  }
}

#endif // !VECTOR_2D_H
