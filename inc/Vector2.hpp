#pragma once
#include <utility>
#include <ios>
#include <cmath>
#include <numbers>
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "Angle.hpp"

template <typename T>
struct Vector2
{
    T x, y;

    /// @brief Default constructor
    constexpr Vector2()
        : x(), y()
    {
    }

    /// @brief Single Value Constructor
    /// @param xy_ Value for both x and y
    constexpr Vector2(T xy_)
        : x(xy_), y(xy_)
    {
    }

    /// @brief Parameterized constructor
    /// @param x_ Value for x
    /// @param y_ Value for y
    constexpr Vector2(T x_, T y_)
        : x(x_), y(y_)
    {
    }

    /// @brief Constructor from std::pair
    /// @param p
    constexpr Vector2(const std::pair<T, T> &p)
        : x(p.first), y(p.second)
    {
    }

    /// @brief Move constructor from pair
    constexpr Vector2(std::pair<T, T> &&p)
        : x(std::move(p.first)), y(std::move(p.second))
    {
    }

    /// @brief Copy constructor
    constexpr Vector2(const Vector2 &v) = default;

    /// @brief Move constructor
    constexpr Vector2(Vector2 &&v) = default;

    /// @brief Returns the angle of the Vector2
    [[nodiscard]] constexpr Angle getAngle() const
    {
        return radians(std::atan2(y, x));
    }

    /// @brief Returns the length of the Vector2
    [[nodiscard]] constexpr T getLength() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// @brief Sets the angle of the Vector2 while leaving the length unchanged
    constexpr Vector2<T> &setAngle(Angle ang)
    {
        double len = getLength();

        x = len * cos(ang.getRadians());
        y = len * sin(ang.getRadians());

        return *this;
    }

    /// @brief Sets the length of the Vector2 while leaving the angle unchanged
    constexpr Vector2<T> &setLength(double len)
    {
        Angle ang = getAngle();

        x = len * cos(ang.getRadians());
        y = len * sin(ang.getRadians());

        return *this;
    }

    /// @brief Swaps the x and y components of the vector
    constexpr Vector2<T> &swap()
    {
        std::swap(x, y);
        return *this;
    }

    /// @brief Returns the unit vector (Vector with length 1)
    constexpr Vector2<T> &unify()
    {
        const T len = getLength();
        x /= len;
        y /= len;
        return *this;
    }

    /// @brief rotates the vector by ang
    constexpr Vector2<T> &rotate(Angle ang)
    {
        const float cosine = cos(ang.getRadians());
        const float sine = sin(ang.getRadians());

        const T _x = x;

        x = cosine * x - sine * y;
        y = sine * _x + cosine * y;

        return *this;
    }

    /// @brief Translates the vector by another vector
    constexpr Vector2<T> &translate(Vector2<T> offset)
    {
        (*this) += offset;
        return *this;
    }

    /// @brief Scales the vector by a factor
    constexpr Vector2<T> &scale(double factor)
    {
        x *= factor;
        y *= factor;
        return *this;
    }

    /// @brief Conversion between different Vector2 types
    template <typename To>
    constexpr operator Vector2<To>() const
    {
        return Vector2<To>(static_cast<To>(x), static_cast<To>(y));
    }

    /// @brief Conversion to std::pair
    constexpr operator std::pair<T, T>()
    {
        return std::pair<T, T>(x, y);
    }

    /// @brief Copy assignment operator
    constexpr Vector2<T> &operator=(const Vector2<T> &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    /// @brief Move assignment operator
    template <typename To>
    constexpr Vector2<T> &operator=(Vector2<To> &&other)
    {
        x = std::move(other.x);
        y = std::move(other.y);
        return *this;
    }
};

/// @brief Addition operator
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> operator+(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}

/// @brief Addition assignment operator
template <typename Ta, typename Tb>
constexpr Vector2<Ta> operator+=(Vector2<Ta> &a, const Vector2<Tb> &b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

/// @brief Subtraction operator
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> operator-(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x - b.x, a.y - b.y);
}

/// @brief Subtraction assignment operator
template <typename Ta, typename Tb>
constexpr Vector2<Ta> operator-=(Vector2<Ta> &a, const Vector2<Tb> &b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

/// @brief Negation operator
template <typename Ta>
[[nodiscard]] constexpr Vector2<Ta> operator-(const Vector2<Ta> &a)
{
    return Vector2(-a.x, -a.y);
}

/// @brief Multiplication operator
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> operator*(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x * b.x, a.y * b.y);
}

/// @brief Multiplication assignment operator
template <typename Ta, typename Tb>
constexpr Vector2<Ta> operator*=(Vector2<Ta> &a, const Vector2<Tb> &b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

/// @brief Division operator
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> operator/(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    if (b.x == 0 || b.y == 0)
        throw std::runtime_error("Division by Zero");
    return Vector2(a.x / b.x, a.y / b.y);
}

/// @brief Division assignment operator
template <typename Ta, typename Tb>
constexpr Vector2<Ta> operator/=(Vector2<Ta> &a, const Vector2<Tb> &b)
{
    if (b.x == 0 || b.y == 0)
        throw std::runtime_error("Division by Zero");
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

/// @brief Outstream operator
template <typename T>
constexpr std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
    os << v.x << ',' << v.y;
    return os;
}

/// @brief Equality operator
template <typename Ta, typename Tb>
constexpr std::ostream &operator==(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return (a.x == b.x) && (a.y == b.y);
}

/// @brief Inequality operator
template <typename Ta, typename Tb>
constexpr std::ostream &operator!=(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return (a.x != b.x) || (a.y != b.y);
}

/// @brief Dot product of two vectors
template <typename Ta, typename Tb>
[[nodiscard]] constexpr double dotProduct(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.x * b.x + a.y * b.y;
}

/// @brief Cross Product of two vectors
template <typename Ta, typename Tb>
[[nodiscard]] constexpr double crossProduct(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return a.x * b.y - a.y * b.x;
}

/// @brief Projects one vector onto another
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Tb> project(const Vector2<Ta> &v, const Vector2<Tb> &onto)
{
    return Vector2(dotProduct(v, onto) / (onto.getLength() * onto.getLength())) * onto;
}

/// @brief Rejects one vector from another
template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Tb> reject(const Vector2<Ta> &v, const Vector2<Tb> &from)
{
    return v - project(v, from);
}

/// @brief Commonly used interpolations
namespace Interpolation
{
    /// @brief Linear Interpolation between two vectors
    template <typename Ta, typename Tb>
    [[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> linear(Vector2<Ta> a, Vector2<Tb> b, double t)
    {
        return a + Vector2(t) * (b - a);
    }

    /// @brief Smoothstep Interpolation between two vectors
    template <typename Ta, typename Tb>
    [[nodiscard]] constexpr Vector2<typename std::common_type<Ta, Tb>::type> smoothstep(Vector2<Ta> a, Vector2<Tb> b, double t)
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