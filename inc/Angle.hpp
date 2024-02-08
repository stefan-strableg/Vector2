#pragma once

#include <numbers>
#include <cmath>

class Angle
{
private:
    float _radians;

    /// @brief Parameterized Constructor from degrees. This is private as it is not naturally clear that the constructor takes radians.
    constexpr Angle(float radians)
        : _radians(radians)
    {
    }

    /// @brief This function along with radians() should be used instead of the parameterized constructor
    friend constexpr Angle degrees(float d);
    /// @brief This function along with degrees() should be used instead of the parameterized constructor
    friend constexpr Angle radians(float r);

public:
    /// @brief Default Constructor
    constexpr Angle()
        : _radians(0){};

    /// @brief Returns the Angle in degrees
    [[nodiscard]] constexpr float getDegrees() const
    {
        return _radians / std::numbers::pi * 180.f;
    }

    /// @brief Returns the Angle in radians
    [[nodiscard]] constexpr float getRadians() const
    {
        return _radians;
    }

    /// @brief Wraps the angle to the range of [-180, 180)
    [[nodiscard]] constexpr Angle wrapSigned() const
    {
        const float rad = _radians - std::numbers::pi;
        const float ret = rad - std::ceil(rad / (2.f * std::numbers::pi)) * (2.f * std::numbers::pi);
        if (ret >= 0.f)
            return Angle(ret - std::numbers::pi);
        else
            return Angle(ret + std::numbers::pi);
    }

    /// @brief Wraps the angle to the range of [0, 360)
    [[nodiscard]] constexpr Angle wrapUnsigned() const
    {
        const float ret = _radians - std::ceil(_radians / (2.f * std::numbers::pi)) * (2.f * std::numbers::pi);
        if (ret >= 0.f)
            return Angle(ret);
        else
            return Angle(ret + 2.f * std::numbers::pi);
    }

    /// @brief Conversion to float in radians, for easier use in calculations
    operator float()
    {
        return _radians;
    }

    /// @brief Conversion to double in radians, for easier use in calculations
    operator double()
    {
        return _radians;
    }
};

/// @brief Makes an Angle object from an angle in degrees
[[nodiscard]] constexpr Angle degrees(float d)
{
    return Angle(d / 180.f * std::numbers::pi);
}
/// @brief Makes an Angle object from an angle in radians
[[nodiscard]] constexpr Angle radians(float r)
{
    return Angle(r);
}

/// @brief Equality Operator
[[nodiscard]] bool operator==(const Angle &a, const Angle &b)
{
    return a.getRadians() == b.getRadians();
}

/// @brief Inequality Operator
[[nodiscard]] bool operator!=(const Angle &a, const Angle &b)
{
    return a.getRadians() != b.getRadians();
}

/// @brief Less Operator
[[nodiscard]] bool operator<(const Angle &a, const Angle &b)
{
    return a.getRadians() < b.getRadians();
}

/// @brief Greater Operator
[[nodiscard]] bool operator>(const Angle &a, const Angle &b)
{
    return a.getRadians() > b.getRadians();
}

/// @brief Less-or-equal Operator
[[nodiscard]] bool operator<=(const Angle &a, const Angle &b)
{
    return a.getRadians() <= b.getRadians();
}

/// @brief Greater-or-equal Operator
[[nodiscard]] bool operator>=(const Angle &a, const Angle &b)
{
    return a.getRadians() >= b.getRadians();
}

/// @brief Addition Operator
[[nodiscard]] Angle operator+(const Angle &a, const Angle &b)
{
    return radians(a.getRadians() + b.getRadians());
}
/// @brief Subtraction Operator
[[nodiscard]] Angle operator-(const Angle &a, const Angle &b)
{
    return radians(a.getRadians() - b.getRadians());
}
/// @brief Subtraction Operator
[[nodiscard]] Angle operator-(const Angle &a)
{
    return radians(-a.getRadians());
}
/// @brief Addition assignment Operator
Angle &operator+=(Angle &a, const Angle &b)
{
    return a = a + b;
}
/// @brief Subtraction assignment Operator
Angle &operator-=(Angle &a, const Angle &b)
{
    return a = a - b;
}

/// @brief Multiplication Operator (Element-wise)
[[nodiscard]] Angle operator*(const Angle &a, const Angle &b)
{
    return radians(a.getRadians() * b.getRadians());
}
/// @brief Division Operator
[[nodiscard]] Angle operator/(const Angle &a, const Angle &b)
{
    return radians(a.getRadians() / b.getRadians());
}
/// @brief Multiplication Assignment Operator
Angle &operator*=(Angle &a, const Angle &b)
{
    return a = a * b;
}
/// @brief Division Assignment Operator
Angle &operator/=(Angle &a, const Angle &b)
{
    return a = a / b;
}

/// @brief Modulo Operator
[[deprecated("NYI")]] [[nodiscard]] Angle operator%(const Angle &a, const Angle &b)
{
    const float ret = a.getRadians() - std::ceil(a.getRadians() / 2.f / std::numbers::pi) * 2.f * std::numbers::pi;
    if (ret >= 0.f)
        return radians(ret);
    else
        return radians(ret + 2.f * std::numbers::pi);
}

/// @brief Modulo Assignment Operator
Angle &operator%=(Angle &a, const Angle &b)
{
    return a = a % b;
}

/// @brief Literal Operator for degrees
[[nodiscard]] Angle operator""_deg(long double angle)
{
    return degrees(angle);
}
/// @brief Literal Operator for degrees
[[nodiscard]] Angle operator""_deg(unsigned long long angle)
{
    return degrees(angle);
}
/// @brief Literal Operator for radians
[[nodiscard]] Angle operator""_rad(long double angle)
{
    return radians(angle);
}
/// @brief Literal Operator for radians
[[nodiscard]] Angle operator""_rad(unsigned long long angle)
{
    return radians(angle);
}
