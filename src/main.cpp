#include "..\inc\Vector2.hpp"
#include <iostream>

int main(void)
{
    Vector2i v1(3, 4);

    Vector2f v2 = v1 * Vector2(1.1f);

    std::cout << v2.getLength() << "\n";

    std::cout << v2 - v1 << "\n";
    std::cout << (v2 - v1).yx() << "\n";

    return EXIT_SUCCESS;
}