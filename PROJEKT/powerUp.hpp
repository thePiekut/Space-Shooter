#pragma once

#include <SFML/Graphics.hpp>

struct PowerUp{
    PowerUp(float x,float y);
    auto draw(sf::RenderWindow& window)-> void;
    auto move()->void;
    auto getGlobalBounds()-> sf::FloatRect;
    auto getPosition()->sf::Vector2f;

    sf::RectangleShape power;
    int val;


};