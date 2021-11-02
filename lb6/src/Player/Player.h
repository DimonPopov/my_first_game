#pragma once

#include <iostream>
#include <memory>
#include "Strategy/IUsing.h"
#include "../Elements/IElement.h"
#include "../Elements/Object.h"
#include "../Iterator/Iterator.h"
#include "../Enemy/Behavior/Behavior.h"
#include "../Enemy/IEnemy.h"
#include "../Save/SaveClass.h"



class Iterator;

class Player{
    std::unique_ptr<IUsing> usingStrategy;
    int m_HP;
    int m_coins;
    void setUseStrategy(std::unique_ptr<IUsing>);
public:
    Player();
    int getCoins();
    int getHP();
    void move(std::string route);
    void use();
    void use(std::shared_ptr<IEnemy>);
    unsigned myPositionX();
    unsigned myPositionY();
    std::unique_ptr<Iterator> playerIter;
    int operator+(std::shared_ptr<IElements>) const;
    int operator+(std::shared_ptr<IEnemy>);
    friend class Aggressive;
    friend class SaveClass;
    friend std::ostream& operator<< (std::ostream &out, const Player &P1);
    friend std::ofstream& operator<< (std::ofstream &out, const Player &P1);
};