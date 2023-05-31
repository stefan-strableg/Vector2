#pragma once
#include <utility>
#include <ios>

template <typename T>
struct Vector2
{
    T x, y;

    Vector2()
        : x(), y()
    {
    }

    Vector2(T x_, T _y)
        : x(x_), y(y_)
    {
    }

    Vector2(std::pair<T, T> p)
        : x(p.first), y(p.second)
    {
    }
};

template <typename Ta, typename Tb>
[[nodiscard]] constexpr Vector2<Ta> operator+(const Vector2<Ta> &a, const Vector2<Tb> &b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}

template <typename T>
std::ostream &operator+(std::ostream &os, const Vector2<T> &v)
{
    os << v.x << ',' << v.y;
    return os;
}