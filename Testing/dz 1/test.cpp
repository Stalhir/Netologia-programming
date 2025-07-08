#include <catch2/catch_test_macros.hpp>
#include "main.cpp"
#define CATCH_CONFIG_MAIN


TEST_CASE("Test basic func")
{
    List testList;
    REQUIRE(testList.Empty() == true);

    testList.PushBack(1);
    REQUIRE(testList.Size() == 1);

    
    testList.Clear();
    REQUIRE(testList.Size() == 0);
}