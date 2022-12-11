#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "myproject.h"


TEST_CASE( "Multiplication is valid", "[mul]" ) {
    REQUIRE( myproject::my_mul(1,1) == 1 );
    REQUIRE( myproject::my_mul(1,2) == 2 );
    REQUIRE( myproject::my_mul(2,1) == 2 );
    REQUIRE( myproject::my_mul(2,2) == 4 );
    REQUIRE( myproject::my_mul(9,5) == 45 );
}

TEST_CASE( "Optimized Multiplication is valid", "[mul]" ) {
    REQUIRE( myproject::my_mul_optimized(1,1) == 1 );
    REQUIRE( myproject::my_mul_optimized(1,2) == 2 );
    REQUIRE( myproject::my_mul_optimized(2,1) == 2 );
    REQUIRE( myproject::my_mul_optimized(2,2) == 4 );
    REQUIRE( myproject::my_mul_optimized(9,5) == 45 );
}


