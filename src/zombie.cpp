#include "zombie.h"

Zombie::Zombie(const sf::Vector2f& a_position, const sf::Vector2f& a_speed)
  :drawable(10.f, 4)
  ,position(a_position)
  ,speed(a_speed){
  drawable.setFillColor(sf::Color::Magenta);
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

void Zombie::move(){
  position += speed;
  drawable.move(speed);
}
