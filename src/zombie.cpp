#include "zombie.h"

Zombie::Zombie(const sf::Vector2f& a_position)
  :drawable(sf::Vector2f{20.f, 20.f})
  ,position(a_position){
  drawable.setFillColor(sf::Color::Green);
  drawable.setPosition(position);
}

Zombie::~Zombie(){

}

sf::FloatRect Zombie::bounds(){
  return drawable.getGlobalBounds();
}

void Zombie::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(drawable, states);
};
