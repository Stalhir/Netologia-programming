#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "extended_array.hpp"

TEST_CASE("ExtArray Tests", "[ExtArray]") {
    
    ExtArray<int> emptyArray{};

    SECTION("Size of empty array should be 0") {
        REQUIRE(emptyArray.size() == 0);
    }

    SECTION("Mean of empty array should be 0") {
        REQUIRE(emptyArray.mean() == 0.0);
    }

    SECTION("Median of empty array should be 0") {
        REQUIRE(emptyArray.median() == 0.0);
    }

    SECTION("Mode of empty array should return (0, 0)") {
        REQUIRE(emptyArray.mode() == std::pair<int, int>(0, 0));
    }
}