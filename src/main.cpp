#include "..\inc\Vector2.hpp"
#include <iostream>

int main(void)
{
    Vector2<float> v1(3.f, 4.f);
    Vector2<float> v2(4.f, 3.f);

    std::cout << v1.getLength() << "\n";
    std::cout << v1.getAngle() << "(" << DEG(v1.getAngle()) << ")\n";

    return EXIT_SUCCESS;
}