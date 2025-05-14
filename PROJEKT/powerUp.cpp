
#include "powerUp.hpp"

PowerUp::PowerUp(float x, float y) {
    power.setSize(sf::Vector2f(15, 20));

    power.setPosition(x, y);
    val = rand() % 3;
    if (val == 0) {
        power.setFillColor(sf::Color::Red);
    } else if(val==1){
        power.setFillColor(sf::Color::Green);
    } else if(val==2){
        power.setFillColor(sf::Color::Blue);
    }

}

auto PowerUp::draw(sf::RenderWindow &window) -> void {
    window.draw(power);


}

auto PowerUp::move() -> void {
    power.move(0, 0.1);

}

auto PowerUp::getGlobalBounds() -> sf::FloatRect {
    return power.getGlobalBounds();
}

auto PowerUp::getPosition() -> sf::Vector2f {
    return power.getPosition();
}

