/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   player.cpp
 * Author: vigliag
 *
 * Created on December 17, 2015, 11:52 AM
 */

#include "player.h"
using sf::Vector2f;

Player::Player(){
  drawable.setFillColor(sf::Color::Blue);
  drawable.setOutlineThickness(3);
  drawable.setOutlineColor(sf::Color(250, 150, 100));
  drawable.setPosition(position);
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

sf::FloatRect Player::bounds(){
    return drawable.getGlobalBounds();
}

void Player::move(const Vector2f &movement){
  drawable.move(movement);
}

int Player::recharge(){
  ammo = 1;
  drawable.setFillColor(sf::Color::Green);
  return ammo;
}

bool Player::useAmmo(){
  if (ammo > 0){
    ammo--;
    drawable.setFillColor(sf::Color::Blue);
    return true;
  } else {
    return false;
  }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(drawable, states);
};
