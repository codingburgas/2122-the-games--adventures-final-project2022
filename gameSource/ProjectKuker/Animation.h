#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

public:
    sf::IntRect uvRect;

    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

    void update(int row, float deltaTime);

};
