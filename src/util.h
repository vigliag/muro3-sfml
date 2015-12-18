/* 
 * File:   util.h
 * Author: vigliag
 *
 * Created on December 17, 2015, 4:55 PM
 */
#include <SFML/Graphics.hpp>

#ifndef UTIL_H
#define UTIL_H

sf::Vector2f limitMovementToBound(const sf::FloatRect &limit, const sf::FloatRect &shape, const sf::Vector2f &movement);

#endif /* UTIL_H */

