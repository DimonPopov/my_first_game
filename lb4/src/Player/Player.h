#pragma once

#include <iostream>
#include <memory>
#include "Strategy/IUsing.h"
#include "../Elements/IElement.h"
#include "../Elements/Object.h"
#include "../Iterator/Iterator.h"

class Iterator;

class Player{
    std::unique_ptr<IUsing> usingStrategy;
    std::unique_ptr<Iterator> playerIter;
    int m_HP;
    int m_coins;
    void setUseStrategy(std::unique_ptr<IUsing>);
public:
    Player();
    int getCoins();
    int getHP();
    void move(std::string route);
    void use();
    unsigned myPositionX();
    unsigned myPositionY();
    int operator+(std::shared_ptr<IElements>) const;
    friend std::ostream& operator<< (std::ostream &out, const Player &P1);
    friend std::ofstream& operator<< (std::ofstream &out, const Player &P1);
};