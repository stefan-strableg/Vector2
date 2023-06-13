#pragma once
#include <utility>
#include <ios>
#include <cmath>
#include <numbers>
#include <type_traits>

#define DEG(rad) (rad * 180.f / std::numbers::pi)
#define RAD(deg) (deg / 180.f * std::numbers::pi)

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
        : x(p.first), y(p.second)
    {
    }

    /// @brief Default move constructor
    inline Vector2(Vector2 &&v) = default;

    /// @brief Returns the angle of the Vector2
    [[nodiscard]] inline double getAngle() const
    {
        return std::atan2(y, x);
    }

    /// @brief Returns the length of the Vector2
    [[nodiscard]] inline double getLength() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// @brief Sets the angle of the Vector2 while leaving the length unchanged
    inline void setAngle(double ang)
    {
        double len = getLength();

        x = len * cos(ang);
        y = len * sin(ang);
    }

    /// @brief Sets the length of the Vector2 while leaving the angle unchanged
    inline void setLength(double len)
    {
        double ang = getAngle();

        x = len * cos(ang);
        y = len * sin(ang);
    }

    /// @brief Swaps x and y values
    inline void swap()
    {
        std::swap(x, y);
    }

    /// @brief Returns a copy of the vector with x and y value swapped
    [[nodiscard]] inline Vector2<T> yx() const
    {
        return Vector2<T>(y, x);
    }

    /// @brief Rotates the vector by a specific
    inline void rotate(double rad)
    {
        setAngle(getAngle() + rad);
    }

    /// @brief Returns the unit vector (Vector with length 1)
    inline Vector2<T> unit() const
    {
        Vector2<T> ret;
        ret.setLength(1.f);
        return ret;
    }

    /// @brief Conversion between differend Vector2 types
    template <typename To>
    operator Vector2<To>() const
    {
        return Vector2<To>(static_cast<To>(x), static_cast<To>(y));
    }

    operator std::pair<T, T>()
    {
        return std::pair<T, T>(x, y);
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

/// @brief Stream operator
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
    os << v.x << ',' << v.y;
    return os;
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

// Common Typedefs
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<int> Vector2i;
typedef Vector2<long> Vector2l;
typedef Vector2<long long> Vector2ll;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<unsigned long> Vector2ul;
typedef Vector2<unsigned long long> Vector2ull;