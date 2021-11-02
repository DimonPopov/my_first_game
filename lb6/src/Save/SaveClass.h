#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <memory>

#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Enemy/IEnemy.h"

class Player;
class Enemy1;
class Enemy2;
class Enemy3;

class SaveClass{
    std::ofstream saveFile;
    std::string fileName;
public:
    void saving(std::shared_ptr<Player> player, std::shared_ptr<Map> map, std::shared_ptr<IEnemy> e1, std::shared_ptr<IEnemy> e2, std::shared_ptr<IEnemy> e3);
    void loading(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map, std::shared_ptr<Enemy1> &e1, std::shared_ptr<Enemy2> &e2, std::shared_ptr<Enemy3> &e3);
};