#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f position) {
    bullet.setSize(sf::Vector2f(5, 10));
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setPosition(position);
}

auto Bullet::draw(sf::RenderWindow &window) const -> void {
    window.draw(bullet);

}

auto Bullet::getPosition() -> sf::Vector2f {
    return bullet.getPosition();
}

auto Bullet::move(float x, float y) -> void {
    bullet.move(x,y);

}
auto Bullet::getGlobalBounds()-> sf::FloatRect{
    bullet.getGlobalBounds();
}

float Bullet::getDmg() const {
    return dmg;
}

auto Bullet::destroy() -> void {
    bullet.setPosition(-1,-1);

}


