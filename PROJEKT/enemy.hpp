#pragma once

#include <SFML/Graphics.hpp>
#include "obstacle.hpp"
#include "bullet.hpp"

struct Enemy:Obstacle{
    Enemy( sf::Texture const &texture);

    auto draw(sf::RenderWindow& window)->void override ;
    auto move()->void override;
    auto getGlobalBounds()-> sf::FloatRect override;
    auto damage(float dmg)->void override;
    auto isDead()->bool override;
    auto getPosition()->sf::Vector2f override;
    auto shoot(sf::Clock& clock)->void override;
    auto killNow()->void override;
    auto getBullets()->std::vector<Bullet> override;

    int health;
};