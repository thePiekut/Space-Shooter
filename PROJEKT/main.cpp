#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "player.hpp"
#include "enemy.hpp"
#include "obstacle.hpp"
#include "enemyShooter.hpp"
#include "powerUp.hpp"

auto main() -> int {
    auto window = sf::RenderWindow(
            sf::VideoMode({500, 800}), "Test",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    window.setFramerateLimit(200);

    auto backgroundTexture = sf::Texture();

    if (!backgroundTexture.loadFromFile("background.jpeg")) {
        std::cout << "error z textura background";
    }
    auto background = sf::RectangleShape();
    background.setSize(sf::Vector2f(500, 800));
    background.setPosition(0, 0);
    background.setTexture(&backgroundTexture);


    auto obstacleTexture = sf::Texture();
    if (!obstacleTexture.loadFromFile("obstacle.png")) {
        std::cout << "error z textura obstacle";
    }

    auto enemyTexture = sf::Texture();
    if (!enemyTexture.loadFromFile("enemy.png")) {
        std::cout << "error z textura enemy";
    }

    auto shooterTexture = sf::Texture();
    if (!shooterTexture.loadFromFile("shooter.png")) {
        std::cout << "error z textura shooter";
    }



    auto start = false;
    int money=0;

    sf::Texture playButText;
    if (!playButText.loadFromFile("play.png")) {
        std::cout << "Problem z textura play";
        return -1;
    }

    auto play = sf::RectangleShape(sf::Vector2f(200, 200));
    play.setPosition({150, 300});
    play.setTexture(&playButText);

    sf::Font font;
    if (!font.loadFromFile("ARIBL0.ttf")) {
        std::cout << "problem z font";
    }

    auto plusHp = sf::RectangleShape(sf::Vector2f(100, 100));
    plusHp.setPosition({25, 500});
    plusHp.setFillColor(sf::Color::Yellow);

    sf::Text hpShop;
    hpShop.setPosition(30, 500);
    hpShop.setFont(font);
    hpShop.setCharacterSize(35);
    hpShop.setFillColor(sf::Color::Black);

    std::stringstream hpPlusStr;
    hpPlusStr<< "HP+\n"<<"100$";
    hpShop.setString(hpPlusStr.str());



    auto plusInterval = sf::RectangleShape(sf::Vector2f(100, 100));
    plusInterval.setPosition({200, 500});
    plusInterval.setFillColor(sf::Color::Yellow);

    sf::Text intervalShop;
    intervalShop.setPosition(205, 500);
    intervalShop.setFont(font);
    intervalShop.setCharacterSize(25);
    intervalShop.setFillColor(sf::Color::Black);

    std::stringstream intervalPlusStr;
    intervalPlusStr<< "Fire\nrate+\n"<<"100$";
    intervalShop.setString(intervalPlusStr.str());

    auto plusSpeed = sf::RectangleShape(sf::Vector2f(100, 100));
    plusSpeed.setPosition({375, 500});
    plusSpeed.setFillColor(sf::Color::Yellow);

    sf::Text speedShop;
    speedShop.setPosition(377, 500);
    speedShop.setFont(font);
    speedShop.setCharacterSize(24);
    speedShop.setFillColor(sf::Color::Black);

    std::stringstream speedPlusStr;
    speedPlusStr<< "Speed+\n"<<"100$";
    speedShop.setString(speedPlusStr.str());


    sf::Texture livesTexture;
    if (!livesTexture.loadFromFile("lives.png")) {
        std::cout << "Problem z textura lives";
        return -1;
    }

    auto lives = sf::RectangleShape(sf::Vector2f(20, 20));
    lives.setPosition({0, 0});
    lives.setTexture(&livesTexture);



    sf::Texture coinTexture;
    if (!coinTexture.loadFromFile("coin.png")) {
        std::cout << "Problem z textura coin";
        return -1;
    }
    auto coins = sf::RectangleShape(sf::Vector2f(20, 20));
    coins.setPosition({0, 20});
    coins.setTexture(&coinTexture);

    sf::Text hpPoints;
    hpPoints.setPosition(25, 0);
    hpPoints.setFont(font);
    hpPoints.setCharacterSize(16);
    hpPoints.setFillColor(sf::Color::White);

    sf::Text coinsText;
    coinsText.setPosition(25, 20);
    coinsText.setFont(font);
    coinsText.setCharacterSize(16);
    coinsText.setFillColor(sf::Color::White);

    sf::Text scoreText;
    scoreText.setPosition(210, 0);
    scoreText.setFont(font);
    scoreText.setCharacterSize(18);
    scoreText.setFillColor(sf::Color::White);


    auto player = Player();
    auto bulletTime = sf::Clock();
    auto playerHp = player.health;
    auto playerFireRate=player.interval;

    auto obstacles = std::vector<std::unique_ptr<Obstacle>>();
    auto obstacleTime = sf::Clock();
    auto spawnObstacle = sf::seconds(7);
    auto badBulletTime = sf::Clock();


    auto enemyTime = sf::Clock();
    auto spawnEnemy = sf::seconds(2);

    auto shooterTime = sf::Clock();
    auto spawnShooter = sf::seconds(5);

    auto gameTime = sf::Clock();
    auto points = 0;

    auto powerUps = std::vector<PowerUp>();



    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mousPos = sf::Mouse::getPosition(window);
                    if (play.getGlobalBounds().contains(mousPos.x, mousPos.y)) {
                        start = true;
                    }
                    if (plusHp.getGlobalBounds().contains(mousPos.x, mousPos.y)) {
                        if(money>=100){
                            playerHp++;
                            money-=100;
                        }
                    }
                    if (plusInterval.getGlobalBounds().contains(mousPos.x, mousPos.y)) {
                        if(money>=100){
                            player.interval=player.interval-sf::seconds(0.1);
                            money-=100;
                        }
                    }
                    if (plusSpeed.getGlobalBounds().contains(mousPos.x, mousPos.y)) {
                        if(money>=100){
                            player.speed+=0.1;
                            money-=100;
                        }
                    }
                }
            }

        }
        window.clear();


        if (!start) {
            gameTime.restart();
            points = 0;
            player.health = playerHp;
            player.player.setPosition(215.5, 700);
            obstacles.clear();
            powerUps.clear();

            window.draw(background);

            window.draw(coins);
            window.draw(coinsText);

            window.draw(plusHp);
            window.draw(hpShop);

            window.draw(plusInterval);
            window.draw(intervalShop);

            window.draw(plusSpeed);
            window.draw(speedShop);

            window.draw(play);
        } else if (start) {

            window.draw(background);


            if (obstacleTime.getElapsedTime() >= spawnObstacle) {
                auto obstacle = std::make_unique<Obstacle>(obstacleTexture);
                obstacles.push_back(std::move(obstacle));
                obstacleTime.restart();
            }
            if (enemyTime.getElapsedTime() >= spawnEnemy) {
                auto enemy = std::make_unique<Enemy>(enemyTexture);
                obstacles.push_back(std::move(enemy));
                enemyTime.restart();
            }
            if (shooterTime.getElapsedTime() >= spawnShooter) {
                auto shooter = std::make_unique<EnemyShooter>(shooterTexture);
                obstacles.push_back(std::move(shooter));
                shooterTime.restart();
            }


            player.movement(window);
            player.shoot(bulletTime);


            for (auto &obstacle: obstacles) {
                obstacle->move();
                obstacle->draw(window);
                obstacle->shoot(badBulletTime);
                auto punkty = obstacle->hit(player.getGlobalBounds());
                player.health -= punkty;


            }
            for (auto &powerUp: powerUps) {
                powerUp.move();
                powerUp.draw(window);
            }


            for (auto itO = obstacles.begin(); itO != obstacles.end();) {
                player.kill(**itO);
                player.collision(**itO);
                if ((*itO)->isDead()) {
                    auto random=rand()%100;
                    if(random<=75) {
                        auto powerUp = PowerUp((**itO).getPosition().x, (**itO).getPosition().y);
                        powerUps.push_back(powerUp);
                    }
                        points += (**itO).point;
                        money+=(**itO).point;

                        itO = obstacles.erase(itO);


                } else if ((*itO)->getPosition().y > 800) {
                    itO = obstacles.erase(itO);
                } else {
                    itO++;
                }
            }

            for (auto itP = powerUps.begin(); itP != powerUps.end();) {
                if (player.collect(*itP)) {
                    switch (itP->val) {
                        case 0:
                            player.health += 1;
                            break;
                        case 1:
                            player.powerShoot = true;
                            break;
                        case 2:
                            player.speed=0.5;
                            player.slowTime.restart();
                            break;
                    }
                    itP = powerUps.erase(itP);
                } else if ((*itP).getPosition().y > 800) {
                    itP = powerUps.erase(itP);
                } else
                    itP++;
            }


            if (player.isDead()) {
                start = false;
            }

            player.draw(window);

            std::stringstream stringHp;
            stringHp << "x" << player.health;
            hpPoints.setString(stringHp.str());
            window.draw(lives);
            window.draw(hpPoints);



            sf::Time currentScore = gameTime.getElapsedTime();
            auto score = static_cast<int>(currentScore.asSeconds()) + points;
            std::stringstream scoreStr;
            scoreStr << "Score: " << score;
            scoreText.setString(scoreStr.str());
            window.draw(scoreText);


        }

        std::stringstream coinString;
        coinString << "x" << money;
        coinsText.setString(coinString.str());
        window.draw(coins);
        window.draw(coinsText);


        window.display();

    }
}

