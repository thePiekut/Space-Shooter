
#include "enemy.hpp"
#include <iostream>

Enemy::Enemy(sf::Texture const &texture) : Obstacle(texture) {

    obstacle.setSize(sf::Vector2f(50, 30));
    obstacle.setPosition(sf::Vector2f(rand() % 475, -50));
    obstacle.setTexture(&texture);
    health = 3;
    dmg = 1;
    point=5;


}

auto Enemy::draw(sf::RenderWindow &window) -> void {
    window.draw(obstacle);
}

auto Enemy::move() -> void {
    obstacle.move(0, 0.5);
}

auto Enemy::damage(float dmg) -> void {
    health -= dmg;
}

auto Enemy::isDead() -> bool {
    return health <= 0;
}

auto Enemy::getGlobalBounds() -> sf::FloatRect {
    return Obstacle::getGlobalBounds();
}

auto Enemy::getPosition() -> sf::Vector2f {
    return Obstacle::getPosition();
}

auto Enemy::shoot(sf::Clock &clock) -> void {

}

auto Enemy::killNow() -> void {
    Obstacle::killNow();
}

auto Enemy::getBullets() -> std::vector<Bullet> {
    return Obstacle::getBullets();
}


