cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra)

add_executable(main main.cpp sort_file.hpp my_sort.hpp)
