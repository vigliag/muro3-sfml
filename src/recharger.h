#include <SFML/Graphics.hpp>

#ifndef RECHARGER_H
#define RECHARGER_H

class Recharger : public sf::Drawable {
public:
  Recharger(const sf::Vector2f& position);
  virtual ~Recharger();
  sf::RectangleShape drawable;
  sf::Vector2f position;
  sf::FloatRect bounds();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
