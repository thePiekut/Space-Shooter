#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include "obstacle.hpp"
#include "powerUp.hpp"


struct Player{
    Player();
    auto movement(sf::RenderWindow& window)->void ;
    auto draw(sf::RenderWindow& window)->void ;
    auto getSize()->sf::Vector2f;
    auto getPosition()->sf::Vector2f;
    auto shoot(sf::Clock& clock)->void;
    auto kill(Obstacle& obstacle)->void;
    auto collision(Obstacle& obstacle)->void;
    auto isDead()->bool;
    auto getGlobalBounds()->sf::Rect<float>;
    auto collect(PowerUp& powerUp)->bool;


    sf::Texture playerTexture;
    sf::RectangleShape player;
    std::vector<Bullet> bullets;
    float speed=1;
    float speedOg=1;
    sf::Clock slowTime;
    int health;
    sf::Time interval=sf::seconds(1);
    sf::Time intervalOg=sf::seconds(1);
    bool powerShoot;
    sf::Clock powerTime;


};
