#pragma one

#include "enemy.hpp"
#include "bullet.hpp"
#include "player.hpp"

struct EnemyShooter: Enemy{
    EnemyShooter(sf::Texture const &texture);

    auto draw(sf::RenderWindow& window)->void override ;
    auto move()->void override;
    auto getGlobalBounds()-> sf::FloatRect override;
    auto damage(float dmg)->void override;
    auto isDead()->bool override;
    auto getPosition()->sf::Vector2f override;
    auto shoot(sf::Clock& clock)->void override;
    auto getBullets()->std::vector<Bullet> override;
    auto killNow()->void override;

    sf::Time interval=sf::seconds(3);


};