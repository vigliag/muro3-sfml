#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <iostream>
#include "player.h"
#include "util.h"

using std::make_unique;
using sf::Vector2f;
using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 300), "SFML works!");
    const auto screen = sf::FloatRect(0,0,200,300);

    auto playerShape = std::unique_ptr<sf::Shape>(new sf::CircleShape(10.f));
    playerShape->setFillColor(sf::Color::Green);
    auto player = Player(std::move(playerShape));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //handle inputs
        Vector2f requestedMovement{0.f,0.f};

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          requestedMovement = Vector2f{0.5f,0.f};
          cout << "right" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
          requestedMovement = Vector2f{-0.5f,0.f};
          cout << "left" << endl;
        }

        //compute movement and move player
        const Vector2f possibleMovement = limitMovementToBound(screen, player.bounds(), requestedMovement);
        player.move(possibleMovement);

        //draw
        window.clear();
        window.draw(*player.drawable);
        window.display();
    }

    return 0;
}
