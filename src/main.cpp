#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <iostream>

#include "player.h"
#include "util.h"
#include "recharger.h"

using std::make_unique;
using sf::Vector2f;
using std::cout;
using std::endl;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!", sf::Style::Default, settings);
  const auto screen = sf::FloatRect(0,0,WIDTH,HEIGHT);

  auto player = Player();
  auto recharger = Recharger(Vector2f{150,20});

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
      bool shoot = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        requestedMovement = Vector2f{1.f,0.f};
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        requestedMovement = Vector2f{-1.f,0.f};
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        shoot = true;
      }

      //compute movement and move player
      const Vector2f possibleMovement = limitMovementToBound(screen, player.bounds(), requestedMovement);
      player.move(possibleMovement);

      //give ammo to player
      if(player.bounds().intersects(recharger.bounds())){
        player.recharge();
      }

      //handle shooting
      if (shoot && player.useAmmo()){

      }

      //draw
      window.clear();
      window.draw(recharger);
      window.draw(player);
      window.display();
  }

  return 0;
}
