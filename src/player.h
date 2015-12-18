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

class Player {
public:
    Player(std::unique_ptr<sf::Shape>&&);
    Player(const Player& orig);
    virtual ~Player();
    sf::FloatRect bounds();

    void move(const sf::Vector2f& movement);

    bool hasAmmo = false;
    sf::Vector2f position;
    std::unique_ptr<sf::Shape> drawable;
private:

};

#endif /* PLAYER_H */
