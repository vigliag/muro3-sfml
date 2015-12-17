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

Player::Player(std::unique_ptr<sf::Shape> &&s)
    :hasAmmo(false)
    ,drawable(std::move(s))
{
    drawable->setPosition(position);
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

sf::FloatRect Player::bounds(){
    return drawable->getGlobalBounds();
}

void Player::move(const Vector2f &movement){
  drawable->move(movement);
}
