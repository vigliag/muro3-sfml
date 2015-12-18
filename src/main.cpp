#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

#include <memory>
#include <iostream>
#include <math.h>
#include <list>

#include "player.h"
#include "util.h"
#include "recharger.h"
#include "zombie.h"

using std::make_unique;
using sf::Vector2f;
using std::cout;
using std::endl;
using sf::Font;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!", sf::Style::Default, settings);
  const auto screen = sf::FloatRect(0,0,WIDTH,HEIGHT);

  sf::Clock clock;
  float lastUpdateTime = clock.getElapsedTime().asSeconds();

  auto player = Player();
  auto recharger = Recharger(Vector2f{150,20});
  bool gameOver = false;

  sf::Font font;
  font.loadFromFile("res/cubic.ttf");

  sf::Text gameOverText{"Game over", font, 30};
  gameOverText.setPosition(300, 40);
  gameOverText.setColor(sf::Color::Red);

  gameOverText.setString("Game Over");

  std::list<Zombie> zombies;
  //std::list<Projectile> projectiles;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      //TODO reset game. Delete all zombies and projectiles and set gameover=false
      return 0;
    }

    if (!gameOver) {
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

      //tick every second
      float currentTime = clock.getElapsedTime().asSeconds();
      if(currentTime - lastUpdateTime > 1){
        lastUpdateTime = currentTime;

        //Zombie generation logic
        int maxZombiesToGenerate = floor(log(currentTime));
        int zombiesToGenerate = 0;
        for( int i = 0; i < maxZombiesToGenerate; i++ ){
          if (rand() % 2) {
            zombiesToGenerate++;
          }
        }

        //zombie generation
        for (int i=0; i < zombiesToGenerate; i++){
          float position = rand() % (WIDTH-40) + 20;
          zombies.emplace_back(Vector2f{position, HEIGHT-90}, Vector2f{0.f, -0.3f});
        }

      }

      //move zombies and projectiles and check for game over
      for(auto &zombie: zombies){
        if (zombie.position.y < 40){
          gameOver = true;
        }
        zombie.move();
      }

    }

    //draw
    window.clear();
    window.draw(recharger);
    window.draw(player);

    for(auto zombie: zombies){
      window.draw(zombie);
    }

    if(gameOver){
      window.draw(gameOverText);
    }

    window.display();
  }

  return 0;
}
