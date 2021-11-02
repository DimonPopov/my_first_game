#pragma once

#include <iostream>

class Map_Iterator;
class Map;
class IElements;
class IUsing;
class Cell;

class Player{
    IUsing* usingStrategy;
    Map_Iterator *iter;
    int m_HP;
    int m_coins;
    void setUseStrategy(IUsing*);
public:
    Player();
    ~Player();
    int getCoins();
    int getHP();
    void move();
    void doIt();
    friend std::ostream& operator<< (std::ostream &out, const Player &P1);
    friend std::ofstream& operator<< (std::ofstream &out, const Player &P1);
};