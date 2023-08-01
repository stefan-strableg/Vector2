#include "..\inc\Vector2.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(void)
{
    Angle a(360);
    Angle b(0);
    Angle c(180);
    Angle d(-180);

    std::cout << a.wrapUnsigned().getDegrees() << "\n";
    std::cout << b.wrapUnsigned().getDegrees() << "\n";
    std::cout << c.wrapSigned().getDegrees() << "\n";
    std::cout << d.wrapSigned().getDegrees() << "\n";

    return EXIT_SUCCESS;
}