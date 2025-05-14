#pragma once

#include <SFML/Graphics.hpp>
#include "bullet.hpp"


struct Obstacle{
    Obstacle(sf::Texture const& texture);

    virtual auto draw(sf::RenderWindow& window)->void;
    virtual auto move()->void;
    virtual auto getGlobalBounds()-> sf::FloatRect;
    virtual auto damage(float dmg)->void;
    virtual auto isDead()->bool;
    virtual auto getPosition()->sf::Vector2f;
    virtual auto shoot(sf::Clock& clock)->void;
    virtual auto killNow()->void;
    virtual auto getBullets()->std::vector<Bullet>;
    auto hit(sf::Rect<float> const position)->int;


    std::vector<Bullet> bullets;
    sf::RectangleShape obstacle;
    int dmg;
    int point;

};
