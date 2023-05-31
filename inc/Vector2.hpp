#pragma once
#include <utility>
#include <ios>
#include <cmath>
#include <numbers>

#define DEG(rad) (rad * 180.f / std::numbers::pi)
#define RAD(deg) (deg / 180.f * std::numbers::pi)

template <typename T>
struct Vector2
{
    T x, y;

    inline Vector2()
        : x(), y()
    {
    }

    inline Vector2(T x_, T y_)
        : x(x_), y(y_)
    {
    }

    inline Vector2(std::pair<T, T> p)
        : x(p.first), y(p.second)
    {
    }

    /// @brief Returns the angle of the Vector2
    [[nodiscard]] inline double angle() const
    {
        return std::atan2(y, x);
    }

    /// @brief Returns the length of the Vector2
    [[nodiscard]] inline double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// @brief Sets the angle of the Vector2 while leaving the length unchanged
    inline void angle(double ang)
    {
        double len = length();

        x = len * cos(ang);
        y = len * sin(ang);
    }

    /// @brief Sets the length of the Vector2 while leaving the angle unchanged
    inline void length(double len)
    {
        double ang = angle();

        x = len * cos(ang);
        y = len * sin(ang);
    }

    /// @brief Swaps x and y values
    inline void swap()
    {
        std::swap(x, y);
    }

    /// @brief Rotates the vector by a specific
    inline void rotate(double rad)
    {
        angle(angle() + rad);
    }
};

template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Ta> operator+(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}

template <typename Ta, typename T>
[[nodiscard]] constexpr Vector2<Ta> operator+(const Vector2<Ta> &a, const T &t)
{
    return Vector2(a.x + t, a.y + t);
}

template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Ta> operator-(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x - b.x, a.y - b.y);
}

template <typename Ta, typename T>
[[nodiscard]] constexpr Vector2<Ta> operator-(const Vector2<Ta> &a, const T &t)
{
    return Vector2(a.x - t, a.y - t);
}

template <typename Ta>
[[nodiscard]] constexpr Vector2<Ta> operator-(const Vector2<Ta> &a)
{
    return Vector2(-a.x, -a.y);
}

template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Ta> operator*(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x * b.x, a.y * b.y);
}

template <typename Ta, typename T>
[[nodiscard]] constexpr Vector2<Ta> operator*(const Vector2<Ta> &a, const T &t)
{
    return Vector2(a.x * t, a.y * t);
}

template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Ta> operator/(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x / b.x, a.y / b.y);
}

template <typename Ta, typename T>
[[nodiscard]] constexpr Vector2<Ta> operator/(const Vector2<Ta> &a, const T &t)
{
    return Vector2(a.x / t, a.y / t);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
    os << v.x << ',' << v.y;
    return os;
}
