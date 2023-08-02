#include "..\inc\Vector2.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(void)
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

    a.rotate(degrees(90));
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
    c += b;
    std::cout << "c += b; " << c << " += " << b << " = " << c << "\n";
    c -= b;
    std::cout << "c -= b; " << c << " -= " << b << " = " << c << "\n";
    c *= b;
    std::cout << "c *= b; " << c << " *= " << b << " = " << c << "\n";
    c /= a;
    std::cout << "c /= a; " << c << " /= " << a << " = " << c << "\n";

    b = a;

    std::cout << "\n LOGIC OPERATORS:\n\n";

    return EXIT_SUCCESS;
}