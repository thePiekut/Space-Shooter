
#include "obstacle.hpp"

Obstacle::Obstacle(const sf::Texture &texture) {
    obstacle.setSize(sf::Vector2f(75, 75));
    obstacle.setPosition(sf::Vector2f(rand() % 450, -75));
    obstacle.setTexture(&texture);
    dmg=9999;
    point=0;
}

auto Obstacle::draw(sf::RenderWindow &window) -> void {
    window.draw(obstacle);
}

auto Obstacle::move() -> void {
    obstacle.move(0, 0.2);
}

auto Obstacle::getGlobalBounds() -> sf::FloatRect {
    return obstacle.getGlobalBounds();
}

auto Obstacle::damage(float dmg) -> void {}

auto Obstacle::isDead() -> bool {
    return false;
}

auto Obstacle::getPosition() -> sf::Vector2f {
    return obstacle.getPosition();
}

auto Obstacle::shoot(sf::Clock &clock) -> void {

}

auto Obstacle::killNow() -> void {
    obstacle.setPosition(0, 800);

}

auto Obstacle::getBullets() -> std::vector<Bullet> {
    return bullets;
}

auto Obstacle::hit(sf::Rect<float> const position) -> int {
    for (auto it = bullets.begin(); it != bullets.end();) {
        if (position.contains(
                {static_cast<float>(it->getPosition().x), static_cast<float>(it->getPosition().y)})) {
            bullets.erase(it);
            return 1;
        } else
            it++;
    }
    return 0;
}



