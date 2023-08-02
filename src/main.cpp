#include "..\inc\Vector2.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(void)
{
    Vector2 v(9.f, 9.f);

    std::cout << v.rotate(degrees(-90)) << '\n';

    return EXIT_SUCCESS;
}