cmake_minimum_required(VERSION 3.22.0) 
project(Leaver)

include_directories(Leaver)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(LEAVER SHARED Leaver/Leaver.cpp)
add_executable(Leaver DZ11.3/DZ11.2.cpp)

target_link_libraries(Leaver LEAVER)
