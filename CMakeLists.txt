cmake_minimum_required(VERSION 3.28)

project(Vector2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)
add_link_options(-static-libgcc -static-libstdc++)
add_executable(test src/main.cpp)
target_compile_options(test PRIVATE -Wall -Wextra -Wpedantic -static-libgcc -static-libstdc++)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
endif()