#include <catch2/catch_test_macros.hpp>
#include "main.cpp"
#define CATCH_CONFIG_MAIN


TEST_CASE("Test PushBack")
{
    List testList;
    testList.PushBack(12);
    
    REQUIRE(testList.Empty() == false);

    testList.PushBack(-12);

    REQUIRE(testList.Size() == 2);

}

TEST_CASE("Test PushFront")
{
    List testList;
    testList.PushFront(12);

    REQUIRE(testList.Empty() == false);

    testList.PushFront(-12);

    REQUIRE(testList.Size() == 2);

}

TEST_CASE("Test PopBack")
{
    List testList;
    testList.PushFront(12);
    testList.PushFront(122);

    int value = testList.PopBack();
    REQUIRE(value == 12);

    REQUIRE(testList.Empty() == false);
    REQUIRE(testList.Size() == 1);

    testList.PopBack();

    REQUIRE(testList.Empty() == true);
    REQUIRE(testList.Size() == 0);

    REQUIRE(testList.PopBack() == 0);
}


TEST_CASE("Test PopFront")
{
    List testList;

    testList.PushFront(12);
    testList.PushFront(122);

    int value = testList.PopFront();
    REQUIRE(value == 122);

    REQUIRE(testList.Empty() == false);
    REQUIRE(testList.Size() == 1);

    testList.PopFront();

    REQUIRE(testList.Empty() == true);
    REQUIRE(testList.Size() == 0);
    REQUIRE(testList.PopFront() == 0);
}
