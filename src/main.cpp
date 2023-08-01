#include "..\inc\Vector2.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(void)
{
    Vector2f v1(2, 4);
    Vector2f v2(10, 10);

    std::cout << v1 << "\n";
    std::cout << v1.swap() << "\n";
    std::cout << v1.swap().scale(2) << "\n";
    std::cout << v1.swap().scale(2).rotate(RAD(90)) << "\n";
    std::cout << v1.swap().scale(2).rotate(RAD(90)).setAngle(0) << "\n";

    return EXIT_SUCCESS;
}