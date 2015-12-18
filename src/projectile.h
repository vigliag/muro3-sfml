#include <SFML/Graphics.hpp>

#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile : public sf::Drawable {
public:
  Projectile(const sf::Vector2f& position, const sf::Vector2f& speed);
  virtual ~Projectile();

  sf::CircleShape drawable;
  sf::Vector2f position;
  sf::Vector2f speed;
  sf::FloatRect bounds();

  void move();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
