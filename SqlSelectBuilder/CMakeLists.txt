cmake_minimum_required(VERSION 4.0)
project(SqlSelectBuilder)

set(CMAKE_CXX_STANDARD 20)

add_executable(SqlSelectBuilder main.cpp
        SqlSelectQueryBuilder.cpp
        SqlSelectQueryBuilder.h
)

set(PostgreSQL_ADDITIONAL_VERSIONS "17")
#add_subdirectory(lilibpqxx libpqxx-build)

add_subdirectory(libpqxx build-pqxx)
target_link_libraries(SqlSelectBuilder PRIVATE pqxx)