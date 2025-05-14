
#include "player.hpp"
#include "powerUp.hpp"

#include <iostream>


Player::Player(){
    if (!playerTexture.loadFromFile("statek.png")) {
        std::cout<<"Problem z textura gracza";
    }
    player.setSize(sf::Vector2f(75,75));
    player.setPosition(215.5,700);
    player.setTexture(&playerTexture);
    health=2;
    powerShoot= false;



}
auto Player::movement(sf::RenderWindow& window) -> void {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y > 0)
        player.move(0, -speed);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
             player.getPosition().y < window.getSize().y - player.getSize().y)
        player.move(0, speed);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x > 0 - player.getSize().x / 2)
        player.move(-speed, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
             player.getPosition().x < window.getSize().x - player.getSize().x / 2 - 2.5)
        player.move(speed, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && powerShoot){
        interval=sf::seconds(0.1);
        powerTime.restart();
    }
    else if (powerTime.getElapsedTime().asSeconds()>3 && interval==sf::seconds(0.1)){
        powerShoot= false;
        interval=intervalOg;

    } else if(speed==0.5&&slowTime.getElapsedTime().asSeconds()>3){
        speed=speedOg;
    }

}
auto Player::draw(sf::RenderWindow &window) -> void {
    window.draw(player);
    for (const auto &bullet: bullets) {
        bullet.draw(window);
    }

}
auto Player::getSize() -> sf::Vector2f {
    return player.getSize();
}
auto Player::getPosition() -> sf::Vector2f {
    return player.getPosition();
}



auto Player::shoot(sf::Clock &clock) -> void {
    if (clock.getElapsedTime() >= interval) {
        sf::Vector2f place=player.getPosition()+sf::Vector2f (player.getSize().x/2,0);
        Bullet bullet(place);
        bullets.push_back(bullet);
        clock.restart();
    }
    for (auto &bullet: bullets) {
        bullet.move(0,-2);
    }

    for (auto it = bullets.begin(); it != bullets.end();) { //z pentlą pomógł kolega Michał
        if (it->getPosition().y < 0)
            it = bullets.erase(it);
        else
            it++;
    }

}




auto Player::kill(Obstacle& obstacle) -> void {
        for (auto it = bullets.begin(); it != bullets.end();) {
            if (obstacle.getGlobalBounds().contains({static_cast<float>(it->getPosition().x),static_cast<float>(it->getPosition().y)})){
                it = bullets.erase(it);
                obstacle.damage(it->getDmg());

            }
            else
                it++;
        }


}

auto Player::collision(Obstacle& obstacle) -> void {
    if (player.getGlobalBounds().contains(
            {static_cast<float>(obstacle.getPosition().x), static_cast<float>(obstacle.getPosition().y)})) {
        obstacle.killNow();
        health-=obstacle.dmg;
    }
    }




auto Player::isDead() -> bool {
    return health<=0;

}

auto Player::getGlobalBounds() -> sf::Rect<float> {
    return player.getGlobalBounds();
}

auto Player::collect(PowerUp& powerUp) -> bool {
    if (player.getGlobalBounds().contains(
            {static_cast<float>(powerUp.getPosition().x), static_cast<float>(powerUp.getPosition().y)})){
        return true;
    }


}







