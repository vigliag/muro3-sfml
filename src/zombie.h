#include <SFML/Graphics.hpp>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie : public sf::Drawable {
public:
  Zombie(const sf::Vector2f& position);
  virtual ~Zombie();
  sf::RectangleShape drawable;
  sf::Vector2f position;
  sf::FloatRect bounds();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
