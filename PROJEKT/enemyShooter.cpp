
#include "enemyShooter.hpp"
#include "bullet.hpp"

EnemyShooter::EnemyShooter(const sf::Texture &texture) : Enemy(texture) {
    obstacle.setSize(sf::Vector2f(50, 50));
    obstacle.setTexture(&texture);
    health=5;
    dmg=1;
    point=10;


}

auto EnemyShooter::draw(sf::RenderWindow &window) -> void {
    Enemy::draw(window);
    for (const auto &bullet: bullets) {
        bullet.draw(window);
    }
}

auto EnemyShooter::move() -> void {
    obstacle.move(0,0.3);
}

auto EnemyShooter::getGlobalBounds() -> sf::FloatRect {
    return Enemy::getGlobalBounds();
}

auto EnemyShooter::damage(float dmg) -> void {
    Enemy::damage(dmg);
}

auto EnemyShooter::isDead() -> bool {
    return Enemy::isDead();
}

auto EnemyShooter::getPosition() -> sf::Vector2f {
    return Enemy::getPosition();
}

auto EnemyShooter::shoot(sf::Clock &clock) -> void {
    if (clock.getElapsedTime() >= interval) {
        sf::Vector2f place=obstacle.getPosition()+sf::Vector2f (obstacle.getSize().x/2,0);
        Bullet bullet(place);
        bullets.push_back(bullet);
        clock.restart();
    }
    for (auto &bullet: bullets) {
        bullet.move(0,2);
    }
    for (auto it = bullets.begin(); it != bullets.end();) {

        if (it->getPosition().y >800)
            it = bullets.erase(it);
        else
            it++;
    }

}

auto EnemyShooter::getBullets() -> std::vector<Bullet> {
    return Obstacle::getBullets();
}

auto EnemyShooter::killNow() -> void {
    Enemy::killNow();
}






