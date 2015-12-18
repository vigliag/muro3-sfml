#include "recharger.h"

Recharger::Recharger(const sf::Vector2f& a_position)
  :drawable(sf::Vector2f{20.f, 20.f})
  ,position(a_position){
  drawable.setFillColor(sf::Color::Green);
  drawable.setPosition(position);
}

Recharger::~Recharger(){

}

sf::FloatRect Recharger::bounds(){
  return drawable.getGlobalBounds();
}

void Recharger::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(drawable, states);
};
