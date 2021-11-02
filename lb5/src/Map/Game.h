#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../Player/Player.h"
#include "../Enemy/IEnemy.h"
#include "Map.h"
#include "GameSetting.h"


class Game{
    std::shared_ptr<GameSetting> setting;
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