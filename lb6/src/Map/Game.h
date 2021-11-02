#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../Player/Player.h"
#include "../Enemy/IEnemy.h"
#include "Map.h"
#include "GameSetting.h"
#include "../Save/SaveClass.h"



class Game{
    std::shared_ptr<GameSetting> setting;
    std::shared_ptr<Map> map;
    std::shared_ptr<Player> player;
    sf::RenderWindow window;
    std::unique_ptr<SaveClass> save;
    std::shared_ptr<Enemy1> enemy1;
    std::shared_ptr<Enemy2> enemy2;
    std::shared_ptr<Enemy3> enemy3;
public:
    Game();
    void menuWindow();
    void playerMove(std::string route);
    void newGame();
    void loadGame();
    void endGame();
};