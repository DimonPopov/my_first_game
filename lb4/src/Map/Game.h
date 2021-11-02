#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../Player/Player.h"
#include "Map.h"


class Game{
    std::shared_ptr<Map> map;
    std::unique_ptr<Player> player;
    sf::RenderWindow window;
public:
    void menuWindow();
    void playerMove(std::string route);
    void newGame();
    void loadGame();
    void endGame();
};