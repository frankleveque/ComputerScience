#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "hexconverter.hpp"
#include "b64converter.hpp"

TEST_CASE("Hex tests", "[hex]"){
    HexConverter hc;
    REQUIRE(hc.encodeIntoUpperCase("asdf") == "61736466");
    REQUIRE(hc.encodeIntoUpperCase("") == "");
}


TEST_CASE("B64 tests", "[b64]"){
    Base64Converter bc;

}
