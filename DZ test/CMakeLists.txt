cmake_minimum_required(VERSION 3.5)
project(testsExtArray LANGUAGES CXX VERSION 0.0.1)

add_subdirectory(lib/Catch2)
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain) 