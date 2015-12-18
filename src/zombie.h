#include <SFML/Graphics.hpp>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie : public sf::Drawable {
public:
  Zombie(const sf::Vector2f& position, const sf::Vector2f& speed);
  virtual ~Zombie();

  sf::CircleShape drawable;
  sf::Vector2f position;
  sf::Vector2f speed;
  sf::FloatRect bounds();

  void move();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
