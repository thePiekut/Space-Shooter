cmake_minimum_required(VERSION 3.27)
project(PROJEKT)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)


set(CMAKE_CXX_STANDARD 20)

add_executable(PROJEKT main.cpp
        player.cpp
        player.hpp
        bullet.cpp
        bullet.hpp
        enemy.cpp
        enemy.hpp
        obstacle.cpp
        obstacle.hpp
        enemyShooter.cpp
        enemyShooter.hpp
        powerUp.cpp
        powerUp.hpp
)
target_link_libraries(PROJEKT sfml-graphics)