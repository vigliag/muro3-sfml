#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "../lib/catch.hpp"
#include "../src/util.h"


TEST_CASE( "limitMovementToBound" ) {
    using sf::Vector2f;
    using sf::FloatRect;

    //left, top, width, height
    const FloatRect limit(0.f, 0.f, 200.f, 300.f);
    const FloatRect player(1.f, 20.f, 20.f, 20.f);

    REQUIRE( limitMovementToBound(limit, player, Vector2f{-1.f, 0.f}).x == -1.f );
    REQUIRE( limitMovementToBound(limit, player, Vector2f{ 1.f, 0.f}).x == 1.f );
    REQUIRE( limitMovementToBound(limit, player, Vector2f{-40.f, 0.f}).x == -1.f );
    REQUIRE( limitMovementToBound(limit, player, Vector2f{+400.f, 0.f}).x == 179.f );
}
