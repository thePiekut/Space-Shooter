#pragma once
#include <SFML/Graphics.hpp>

struct Bullet{
    Bullet(sf::Vector2f position);
    auto draw(sf::RenderWindow& window) const ->void;
    auto getPosition()->sf::Vector2f;
    auto move(float x, float y)->void ;
    auto getGlobalBounds()-> sf::FloatRect;
    float getDmg() const;
    auto destroy()->void;

private:
    sf::RectangleShape bullet;
    float dmg=1;

};
