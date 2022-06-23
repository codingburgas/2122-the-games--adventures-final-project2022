#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{
private:
    //variables
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

    //functions


public:
    //variables
    sf::IntRect uvRect;

    //constructor && destructor
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    virtual ~Animation();

    void update(int row, float deltaTime);

};

#endif // ANIMATION_H
