#pragma once

#include <numbers>
#include <cmath>

class Angle
{
private:
    float _degrees;

public:
    /// @brief Default Constructor
    constexpr Angle() = default;
    /// @brief Parameterized Constructor
    constexpr Angle(float degrees)
    {
        _degrees = degrees;
    }

    /// @brief Returns the Angle in degrees
    [[nodiscard]] constexpr float getDegrees() const
    {
        return _degrees;
    }

    /// @brief Returns the Angle in radians
    [[nodiscard]] constexpr float getRadians() const
    {
        return _degrees * std::numbers::pi / 180.f;
    }

    /// @brief Wraps the angle to the range of [-180, 180)
    [[nodiscard]] constexpr Angle wrapSigned() const
    {
        const float deg = _degrees - 180;
        const float ret = deg - std::ceil(deg / 360.f) * 360.f;
        if (ret >= 0.f)
            return Angle(ret - 180);
        else
            return Angle(ret + 180);
    }

    /// @brief Wraps the angle to the range of [0, 360)
    [[nodiscard]] constexpr Angle wrapUnsigned() const
    {
        const float ret = _degrees - std::ceil(_degrees / 360.f) * 360.f;
        if (ret >= 0.f)
            return Angle(ret);
        else
            return Angle(ret + 360.f);
    }
};

/// @brief Makes a Angle object from an angle in degrees
constexpr Angle degrees(float d)
{
    return Angle(d);
}
/// @brief Makes a Angle object from an angle in radians
constexpr Angle radians(float r)
{
    return Angle(r * 180 / std::numbers::pi);
}

/// @brief Equality Operator
bool operator==(Angle a, Angle b)
{
    return a.getDegrees() == b.getDegrees();
}

/// @brief Inequality Operator
bool operator!=(Angle a, Angle b)
{
    return a.getDegrees() != b.getDegrees();
}

/// @brief Less Operator
bool operator<(Angle a, Angle b)
{
    return a.getDegrees() < b.getDegrees();
}

/// @brief Greater Operator
bool operator>(Angle a, Angle b)
{
    return a.getDegrees() > b.getDegrees();
}

/// @brief Less-or-equal Operator
bool operator<=(Angle a, Angle b)
{
    return a.getDegrees() <= b.getDegrees();
}

/// @brief Greater-or-equal Operator
bool operator>=(Angle a, Angle b)
{
    return a.getDegrees() >= b.getDegrees();
}

/// @brief Addition Operator
Angle operator+(Angle a, Angle b)
{
    return Angle(a.getDegrees() + b.getDegrees());
}
/// @brief Subtraction Operator
Angle operator-(Angle a, Angle b)
{
    return Angle(a.getDegrees() - b.getDegrees());
}
/// @brief Addition assignment Operator
Angle &operator+=(Angle &a, Angle b)
{
    return a = a + b;
}
/// @brief Subtraction assignment Operator
Angle &operator-=(Angle &a, Angle b)
{
    return a = a - b;
}

/// @brief Multiplication Operator (Element-wise)
Angle operator*(Angle a, Angle b)
{
    return Angle(a.getDegrees() * b.getDegrees());
}
/// @brief Division Operator
Angle operator/(Angle a, Angle b)
{
    return Angle(a.getDegrees() / b.getDegrees());
}
/// @brief Multiplication Assignment Operator
Angle &operator*=(Angle &a, Angle b)
{
    return a = a * b;
}
/// @brief Division Assignment Operator
Angle &operator/=(Angle &a, Angle b)
{
    return a = a / b;
}

/// @brief Modulo Operator
Angle operator%(Angle a, Angle b)
{
    const float ret = a.getDegrees() - std::ceil(a.getDegrees() / 360.f) * 360.f;
    if (ret >= 0.f)
        return Angle(ret);
    else
        return Angle(ret + 360.f);
}
/// @brief Modulo Assignment Operator
Angle &operator%=(Angle &a, Angle b)
{
    return a = a % b;
}

/// @brief Literal Operator for degrees
Angle operator""_deg(long double angle)
{
    return degrees(angle);
}
/// @brief Literal Operator for degrees
Angle operator""_deg(unsigned long long angle)
{
    return degrees(angle);
}
/// @brief Literal Operator for radians
Angle operator""_rad(long double angle)
{
    return radians(angle);
}
/// @brief Literal Operator for radians
Angle operator""_rad(unsigned long long angle)
{
    return radians(angle);
}
