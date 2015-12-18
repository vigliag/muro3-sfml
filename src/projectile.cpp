#include "projectile.h"

Projectile::Projectile(const sf::Vector2f& a_position, const sf::Vector2f& a_speed)
  :drawable(10.f, 6)
  ,position(a_position)
  ,speed(a_speed){
  drawable.setFillColor(sf::Color::Green);
  drawable.setPosition(position);
}

Projectile::~Projectile(){

}

sf::FloatRect Projectile::bounds(){
  return drawable.getGlobalBounds();
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(drawable, states);
};

void Projectile::move(){
  position += speed;
  drawable.move(speed);
}
