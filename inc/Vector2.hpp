#pragma once
#include <utility>
#include <ios>
#include <cmath>
#include <numbers>
#include <type_traits>
#include <algorithm>

#include "Angle.hpp"

template <typename T>
struct Vector2
{
    T x, y;

    /// @brief Default constructor
    inline Vector2()
        : x(), y()
    {
    }

    /// @brief Single Value Constructor
    /// @param xy_ Value for both x and y
    inline Vector2(T xy_)
        : x(xy_), y(xy_)
    {
    }

    /// @brief Parameterized constructor
    /// @param x_ Value for x
    /// @param y_ Value for y
    inline Vector2(T x_, T y_)
        : x(x_), y(y_)
    {
    }

    /// @brief Constructor from std::pair
    /// @param p
    inline Vector2(const std::pair<T, T> &p)
        : x(p.first), y(p.second)
    {
    }

    /// @brief Move constructor from pair
    inline Vector2(std::pair<T, T> &&p)
        : x(std::move(p.first)), y(std::move(p.second))
    {
    }

    /// @brief Copy constructor
    inline Vector2(const Vector2 &v) = default;

    /// @brief Move constructor
    inline Vector2(Vector2 &&v) = default;

    /// @brief Returns the angle of the Vector2
    [[nodiscard]] inline Angle getAngle() const
    {
        return std::atan2(y, x);
    }

    /// @brief Returns the length of the Vector2
    [[nodiscard]] inline T getLength() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// @brief Chainable. Sets the angle of the Vector2 while leaving the length unchanged
    inline Vector2<T> setAngle(Angle ang)
    {
        double len = getLength();

        x = len * cos(ang.getRadians());
        y = len * sin(ang.getRadians());

        return *this;
    }

    /// @brief Chainable. Sets the length of the Vector2 while leaving the angle unchanged
    inline Vector2<T> setLength(double len)
    {
        Angle ang = getAngle();

        x = len * cos(ang.getRadians());
        y = len * sin(ang.getRadians());

        return *this;
    }

    /// @brief Returns a copy of the vector with x and y value swapped
    [[nodiscard]] inline Vector2<T> swap() const
    {
        return Vector2<T>(y, x);
    }

    /// @brief Chainable. Returns the unit vector (Vector with length 1)
    inline Vector2<T> unit() const
    {
        Vector2<T> ret(*this);
        ret.setLength(1.f);
        return ret;
    }

    /// @brief Chainable. Returns a by rad radiants rotated copy of the vector
    inline Vector2<T> rotate(Angle ang) const
    {
        Vector2<T> ret(*this);
        ret.setAngle(getAngle() + ang.getRadians());
        return ret;
    }

    /// @brief Chainable. Returns an offset copy of the vector by a translation vector
    inline Vector2<T> translate(Vector2<T> offset) const
    {
        return *this + offset;
    }

    /// @brief Chainable. Returns a copy of the vector multiplied by a factor
    inline Vector2<T> scale(double factor) const
    {
        return *this * Vector2(factor);
    }

    /// @brief Chainable. Returns a copy of the vector mirrored at an axis
    template <typename Ta>
    inline Vector2<T> mirror(Vector2<Ta> axis) const
    {
        if (axis.getLength() == 0)
            return *this;

        axis = axis.rotate(-90).unit();
        return *this - Vector2(2) * Vector2(dotProduct(*this, axis)) * axis;
    }

    /// @brief Conversion between different Vector2 types
    template <typename To>
    operator Vector2<To>() const
    {
        return Vector2<To>(static_cast<To>(x), static_cast<To>(y));
    }

    /// @brief Conversion to std::pair
    operator std::pair<T, T>()
    {
        return std::pair<T, T>(x, y);
    }

    /// @brief Copy assignment operator
    template <typename To>
    Vector2<T> &operator=(const Vector2<To> &other)
    {
        x = other.x;
        y = other.y;
    }

    /// @brief Move assignment operator
    template <typename To>
    Vector2<T> &operator=(Vector2<To> &&other)
    {
        x = std::move(other.x);
        y = std::move(other.y);
        return *this;
    }
};

/// @brief Addition operator
template <typename Ta, typename Tb>
[[nodiscard]] inline Vector2<typename std::common_type<Ta, Tb>::type> operator+(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}

/// @brief Subtraction operator
template <typename Ta, typename Tb>
[[nodiscard]] inline Vector2<typename std::common_type<Ta, Tb>::type> operator-(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x - b.x, a.y - b.y);
}

/// @brief Negation operator
template <typename Ta>
[[nodiscard]] inline Vector2<Ta> operator-(const Vector2<Ta> &a)
{
    return Vector2(-a.x, -a.y);
}

/// @brief Multiplication operator
template <typename Ta, typename Tb>
[[nodiscard]] inline Vector2<typename std::common_type<Ta, Tb>::type> operator*(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x * b.x, a.y * b.y);
}

/// @brief Division operator
template <typename Ta, typename Tb>
[[nodiscard]] inline Vector2<typename std::common_type<Ta, Tb>::type> operator/(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x / b.x, a.y / b.y);
}

/// @brief Outstream operator
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
    os << v.x << ',' << v.y;
    return os;
}

/// @brief Less operator
template <typename Ta, typename Tb>
inline std::ostream &operator<(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.getLength() < b.getLength();
}

/// @brief Greater operator
template <typename Ta, typename Tb>
inline std::ostream &operator>(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.getLength() > b.getLength();
}

/// @brief Less-or-equal operator
template <typename Ta, typename Tb>
inline std::ostream &operator<=(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.getLength() <= b.getLength();
}

/// @brief Greater-or-equal operator
template <typename Ta, typename Tb>
inline std::ostream &operator>=(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.getLength() >= b.getLength();
}

/// @brief Equality operator
template <typename Ta, typename Tb>
inline std::ostream &operator==(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return (a.x == b.x) && (a.y == b.y);
}

/// @brief Inequality operator
template <typename Ta, typename Tb>
inline std::ostream &operator!=(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return (a.x != b.x) || (a.y != b.y);
}

/// @brief Dot product of two vectors
template <typename Ta, typename Tb>
[[nodiscard]] inline double dotProduct(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.x * b.x + a.y * b.y;
}

/// @brief Cross Product of two vectors
template <typename Ta, typename Tb>
[[nodiscard]] inline double crossProduct(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.x * b.y - a.y * b.x;
}

/// @brief Projects one vector onto another
template <typename Ta, typename Tb>
inline Vector2<Tb> project(const Vector2<Ta> &v, const Vector2<Tb> &onto)
{
    return Vector2(dotProduct(v, onto) / (onto.getLength() * onto.getLength())) * onto;
}

// Ostiiiii
/// @brief Rejects one vector from another
template <typename Ta, typename Tb>
[[deprecated("This does not work yet!")]] inline Vector2<Tb> reject(const Vector2<Ta> &v, const Vector2<Tb> &from)
{
    return project(v, from.rotate(90));
}

/// @brief Commonly used interpolations
namespace Interpolation
{
    /// @brief Linear Interpolation between two vectors
    template <typename Ta, typename Tb>
    inline Vector2<typename std::common_type<Ta, Tb>::type> linear(Vector2<Ta> a, Vector2<Tb> b, double t)
    {
        return a + Vector2(t) * (b - a);
    }

    /// @brief Smoothstep Interpolation between two vectors
    template <typename Ta, typename Tb>
    inline Vector2<typename std::common_type<Ta, Tb>::type> smoothstep(Vector2<Ta> a, Vector2<Tb> b, double t)
    {
        t = std::clamp(t, 0.0, 1.0);

        float smoothT = t * t * (3 - 2 * t);
        return a + Vector2(smoothT) * (b - a);
    }
}

// Common Typedefs
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<int> Vector2i;
typedef Vector2<long> Vector2l;
typedef Vector2<long long> Vector2ll;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<unsigned long> Vector2ul;
typedef Vector2<unsigned long long> Vector2ull;