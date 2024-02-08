#include "..\inc\Vector2.hpp"
#include "..\inc\Interpolation.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void testVector2();
void testAngle();
void testInterpolation();

int main(void)
{
    testInterpolation();
    return EXIT_SUCCESS;
}

void testInterpolation()
{
    Vector2<float> a(0, 0);
    Vector2<float> b(1, 10);

    std::cout << "Interp::linear between " << a << " and " << b << ":\n";
    for (float f = 0; f < 1.01; f += 0.1)
    {
        std::cout << Interp::linear(a, b, f) << "\n";
    }
    std::cout << "\n";

    std::cout << "Interp::smoothstep between " << a << " and " << b << ":\n";
    for (float f = 0; f < 1.01; f += 0.1)
    {
        std::cout << Interp::smoothstep(a, b, f) << "\n";
    }
    std::cout << "\n";
}

void testVector2()
{

    Vector2 a(2.f, 4.f);
    Vector2f b;
    Vector2 c(a);

    std::cout << " CONSTRUCTION:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << ",\n\tc: (" << c << ") or len "
              << c.getLength() << " ang " << c.getAngle().getDegrees()
              << '\n';

    b.setLength(a.getLength());
    b.setAngle(a.getAngle());

    std::cout << "\n SET LENGTH AND ANGLE:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << '\n';

    a.swap();
    b.unify();

    std::cout << "\n SWAP AND UNIFY:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << '\n';

    a.getRotated(degrees(90));
    b.rotate(degrees(-45));

    std::cout << "\n ROTATE:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << '\n';

    a.translate(Vector2(2, -2));
    b.scale(4);

    std::cout << "\n TRANSLATE AND SCALE:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << '\n';

    a = Vector2(2, 2);
    b = Vector2(4, 0);

    std::cout << "\n RESET TO CLEAR VALUES:\n\n";
    std::cout << "a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees()
              << ",\n\tb: (" << b << ") or len "
              << b.getLength() << " ang " << b.getAngle().getDegrees()
              << '\n';

    auto _a = project(a, b);
    auto _b = reject(a, b);

    std::cout << "\n PROJECTION AND RECTION OF A ONTO/FROM B:\n\n";
    std::cout << "a: (" << _a << ") or len "
              << _a.getLength() << " ang " << _a.getAngle().getDegrees()
              << ",\n\tb: (" << _b << ") or len "
              << _b.getLength() << " ang " << _b.getAngle().getDegrees()
              << '\n';

    std::cout << "\n CROSS AND DOT PRODUCT:\n\n";
    std::cout << "a x b: " << crossProduct(a, b) << "\n"
              << "a . b: " << dotProduct(a, b) << "\n";

    std::cout << "\n ARITHMETICS:\n\n";
    std::cout << "a + b = " << a << " + " << b << " = " << (a + b) << "\n";
    std::cout << "a - b = " << a << " - " << b << " = " << (a - b) << "\n";
    std::cout << "a * b = " << a << " * " << b << " = " << (a * b) << "\n";
    std::cout << "b / a = " << b << " / " << a << " = " << (b / a) << " (b/a because no division by zero)\n";

    std::cout << "\n ASSIGNMENT OPERATORS:\n\n";
    std::cout << "c += b; " << c << " += " << b << " = ";
    c += b;
    std::cout << c << "\n";
    std::cout << "c -= b; " << c << " -= " << b << " = ";
    c -= b;
    std::cout << c << "\n";
    std::cout << "c *= b; " << c << " *= " << b << " = ";
    c *= b;
    std::cout << c << "\n";
    std::cout << "c /= a; " << c << " /= " << a << " = ";
    c /= a;
    std::cout << c << "\n";

    b = a;

    std::cout << "\n LOGIC OPERATORS:\n\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a == c: " << (a == c) << "\n";
    std::cout << "a == b: " << (a != b) << "\n";
    std::cout << "a == c: " << (a != c) << "\n";

    std::cout << "\n CHAINING OPERATORS:\n\n";

    a = Vector2(5, 5);
    a.getRotated(90_deg).getRotated(-3.1415_rad).scale(2).swap().translate(Vector2(-2, 2)).unify();

    std::cout << "chained: a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees() << "\n";

    a = Vector2(5, 5);
    a.getRotated(90_deg);
    a.getRotated(-3.1415_rad);
    a.scale(2);
    a.swap();
    a.translate(Vector2(-2, 2));
    a.unify();

    std::cout << "No chaining: a: (" << a << ") or len "
              << a.getLength() << " ang " << a.getAngle().getDegrees() << "\n";
}

void testAngle()
{
    Angle a(degrees(90));
    Angle b;
    Angle c(a);

    std::cout << " CONSTRUCTION:\n\n";
    std::cout << "a: " << a.getDegrees() << "deg, " << a.getRadians() << "rad\n";
    std::cout << "b: " << b.getDegrees() << "deg, " << b.getRadians() << "rad\n";
    std::cout << "c: " << c.getDegrees() << "deg, " << c.getRadians() << "rad\n";

    std::cout << "\n WRAPPING:\n\n";
    std::cout << "Wrapping 90 deg to signed: " << degrees(90).wrapSigned().getDegrees() << "\n";
    std::cout << "Wrapping 280 deg to signed: " << degrees(280).wrapSigned().getDegrees() << "\n";
    std::cout << "Wrapping 560 deg to signed: " << degrees(560).wrapSigned().getDegrees() << "\n";
    std::cout << "Wrapping 3600 deg to signed: " << degrees(3600).wrapSigned().getDegrees() << "\n\n";
    std::cout << "Wrapping 90 deg to unsigned: " << degrees(90).wrapUnsigned().getDegrees() << "\n";
    std::cout << "Wrapping 280 deg to unsigned: " << degrees(280).wrapUnsigned().getDegrees() << "\n";
    std::cout << "Wrapping 560 deg to unsigned: " << degrees(560).wrapUnsigned().getDegrees() << "\n";
    std::cout << "Wrapping 3600 deg to unsigned: " << degrees(3600).wrapUnsigned().getDegrees() << "\n";

    std::cout << "\n CONVERSION TO FLOATING POINT TYPES:\n\n";
    std::cout << "2.f * (float)a = " << (2.f * (float)a) << "\n";
    std::cout << "2.f * (double)a = " << (2.f * (double)a) << "\n";

    std::cout << "\n DEGREES AND RADIANS:\n\n";
    std::cout << "degrees(90): " << degrees(90).getDegrees() << " deg\n";
    std::cout << "degrees(90): " << degrees(90).getRadians() << " rad\n";
    std::cout << "radians(std::numbers::pi): " << radians(std::numbers::pi).getDegrees() << " deg\n";
    std::cout << "radians(std::numbers::pi): " << radians(std::numbers::pi).getRadians() << " rad\n";

    std::cout << "\n LOGICAL OPERATORS\n\n";
    a = 90_deg;
    b = 45_deg;
    std::cout << "a = " << a.getDegrees() << ", b = " << b.getDegrees() << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n\n";

    a = 45_deg;
    b = 90_deg;
    std::cout << "a = " << a.getDegrees() << ", b = " << b.getDegrees() << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n\n";

    a = 90_deg;
    b = 90_deg;
    std::cout << "a = " << a.getDegrees() << ", b = " << b.getDegrees() << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";

    std::cout << "\n LOGICAL OPERATORS\n\n";
    a = 180_deg;
    b = 90_deg;
    std::cout << "a = " << a.getDegrees() << ", b = " << b.getDegrees() << "\n";
    std::cout << "a + b: " << (a + b).getDegrees() << "\n";
    std::cout << "a - b: " << (a - b).getDegrees() << "\n";
    std::cout << "a * b: " << (a * b).getDegrees() << "\n";
    std::cout << "a / b: " << (a / b).getDegrees() << "\n";
    std::cout << "a % b: " << (a % b).getDegrees() << "\n";
}