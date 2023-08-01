#pragma once

#include <numbers>
#include <cmath>

class Angle
{
private:
    float _degrees;

public:
    constexpr Angle() = default;
    constexpr Angle(float degrees)
    {
        _degrees = degrees;
    }

    [[nodiscard]] constexpr float getDegrees() const
    {
        return _degrees;
    }

    [[nodiscard]] constexpr float getRadians() const
    {
        return _degrees * 180 / std::numbers::pi;
    }

    [[nodiscard]] constexpr Angle wrapSigned() const
    {
        const float deg = _degrees - 180;
        const float ret = deg - std::ceil(deg / 360.f) * 360.f;
        if (ret >= 0.f)
            return Angle(ret - 180);
        else
            return Angle(ret + 180);
    }

    [[nodiscard]] constexpr Angle wrapUnsigned() const
    {
        const float ret = _degrees - std::ceil(_degrees / 360.f) * 360.f;
        if (ret >= 0.f)
            return Angle(ret);
        else
            return Angle(ret + 360.f);
    }
};

constexpr Angle degrees(float d)
{
    return Angle(d);
}
constexpr Angle radians(float r)
{
    return Angle(r * 180 / std::numbers::pi);
}

bool operator==(Angle a, Angle b)
{
    return a.getDegrees() == b.getDegrees();
}

bool operator!=(Angle a, Angle b)
{
    return a.getDegrees() != b.getDegrees();
}

bool operator<(Angle a, Angle b)
{
    return a.getDegrees() < b.getDegrees();
}

bool operator>(Angle a, Angle b)
{
    return a.getDegrees() > b.getDegrees();
}

bool operator<=(Angle a, Angle b)
{
    return a.getDegrees() <= b.getDegrees();
}

bool operator>=(Angle a, Angle b)
{
    return a.getDegrees() >= b.getDegrees();
}

Angle operator+(Angle a, Angle b)
{
    return Angle(a.getDegrees() + b.getDegrees());
}
Angle operator-(Angle a, Angle b)
{
    return Angle(a.getDegrees() - b.getDegrees());
}
Angle &operator+=(Angle &a, Angle b)
{
    return a = a + b;
}
Angle &operator-=(Angle &a, Angle b)
{
    return a = a - b;
}

Angle operator*(Angle a, Angle b)
{
    return Angle(a.getDegrees() * b.getDegrees());
}
Angle operator/(Angle a, Angle b)
{
    return Angle(a.getDegrees() / b.getDegrees());
}
Angle &operator*=(Angle &a, Angle b)
{
    return a = a * b;
}
Angle &operator/=(Angle &a, Angle b)
{
    return a = a / b;
}

Angle operator%(Angle a, Angle b)
{
    const float ret = a.getDegrees() - std::ceil(a.getDegrees() / 360.f) * 360.f;
    if (ret >= 0.f)
        return Angle(ret);
    else
        return Angle(ret + 360.f);
}
Angle &operator%=(Angle &a, Angle b)
{
    return a = a % b;
}

Angle operator""_deg(long double angle)
{
    return degrees(angle);
}
Angle operator""_deg(unsigned long long angle)
{
    return degrees(angle);
}
Angle operator""_rad(long double angle)
{
    return radians(angle);
}
Angle operator""_rad(unsigned long long angle)
{
    return radians(angle);
}
