#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <string>

#include "./Behavior/Behavior.h"
#include "IEnemy.h"




class Enemy3: public IEnemy{
    int at;
    std::shared_ptr<IBehavior> behavior;
public:
    Enemy3();
    void setBehavior(std::shared_ptr<IBehavior> newBehavior);
    unsigned getPositionX();
    unsigned getPositionY();
    void behaviorMove(unsigned x, unsigned y);
    int giveMeAt();
    sf::Sprite Purple;
    sf::Texture PurpleEnemy;
};