#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <string>

#include "Behavior/IBehavior.h"
#include "IEnemy.h"
#include "../Save/SaveClass.h"



class Enemy1: public IEnemy{
    int at;
    std::shared_ptr<IBehavior> behavior;
public:
    Enemy1();
    void setBehavior(std::shared_ptr<IBehavior> newBehavior);
    unsigned getPositionX();
    unsigned getPositionY();
    void behaviorMove(unsigned x, unsigned y);
    int giveMeAt();
    sf::Sprite Red;
    sf::Texture RedEnemy;
    friend class SaveClass;
};