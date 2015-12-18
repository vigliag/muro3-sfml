/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   player.h
 * Author: vigliag
 *
 * Created on December 17, 2015, 11:52 AM
 */

#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H

const float playerY = 20.f;

class Player : public sf::Drawable {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::FloatRect bounds();
    void move(const sf::Vector2f& movement);
    int recharge();
    bool useAmmo();

    unsigned int ammo = 0;
    sf::Vector2f position{0.f, playerY};
    sf::CircleShape drawable{10.f};
private:

};

#endif /* PLAYER_H */
