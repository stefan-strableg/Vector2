#include "..\inc\Vector2.hpp"
#include <iostream>

int main(void)
{
    Vector2<float> v1(3.f, 4.f);
    Vector2<float> v2(4.f, 3.f);

    std::cout << DEG(v1.angle()) << "\n";
    v1.rotate(RAD(90));
    std::cout << DEG(v1.angle()) << "\n";
    v1.rotate(RAD(90));
    std::cout << DEG(v1.angle()) << "\n";
    v1.rotate(RAD(90));
    std::cout << DEG(v1.angle()) << "\n";
    v1.rotate(RAD(90));
    std::cout << DEG(v1.angle()) << "\n";
    return EXIT_SUCCESS;
}