#include "..\inc\Vector2.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include "../inc/Angle.hpp"

int main(void)
{
    Angle a(355 + 360);

    std::cout << a.wrapUnsigned().getDegrees() << "\n";
    std::cout << a.wrapSigned().getDegrees() << "\n";

    return EXIT_SUCCESS;
}