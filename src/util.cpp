#include "util.h"

using sf::FloatRect;
using sf::Vector2f;
using std::max;

/**
 * Limits a movement to remain into a given bound
 * @param bounds
 * @param shape
 * @param movement
 * @return a vector2f with the limited movement. (0.0f, 0.0f) if we are already outside
 */
Vector2f limitMovementToBound(const FloatRect &limit, const FloatRect &shape, const Vector2f &movement){
   // if (!limit.contains(shape)) {return Vector2f(0.0f, 0.0f);}
    Vector2f n_movement(movement);
    if (movement.x > 0){
        auto residualDistFromRight = limit.left + limit.width
            - (shape.left + shape.width + movement.x); 
        if (residualDistFromRight < 0){
            n_movement.x = n_movement.x + residualDistFromRight;
        }
    }
    if (movement.x < 0){
        auto residualDistanceFromLeft = (shape.left + movement.x) - limit.left;
        if (residualDistanceFromLeft < 0){
            n_movement.x = n_movement.x - residualDistanceFromLeft;
        }
    }
     if (movement.y > 0){
        auto residualDistFromBottom = (limit.top + limit.height) 
            - (shape.top + shape.height + movement.y); 
        if (residualDistFromBottom < 0){
            n_movement.y = n_movement.y + residualDistFromBottom;
        }
    }
    if (movement.y < 0){
        auto residualDistFromTop = limit.top - (shape.top + movement.y); 
        if (residualDistFromTop < 0){
            n_movement.y = n_movement.y - residualDistFromTop;
        }
    }
    return n_movement;
}
