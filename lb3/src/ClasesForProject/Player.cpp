#include "Player.h"
#include "Map_Iterator.h"
#include "../Elements/IElements.h"
#include "./UseStrategy/IUsing.h"
#include "./UseStrategy/SnowmanUse.h"
#include "./UseStrategy/WellUse.h"
#include "./UseStrategy/BushUse.h"
#include "Cell.h"
#include "Map.h"
#include "LogClass.h"

#include <iostream>

Player::Player():m_HP(100), m_coins(0){
    iter = new Map_Iterator();
    usingStrategy = nullptr;
}

Player::~Player(){
    delete iter;
    if(usingStrategy){
        delete usingStrategy;
    }
}

int Player::getHP(){ 
    return m_HP; 
    }

int Player::getCoins(){ 
    return m_coins; 
    }

void Player::move(){ 

    std::string route;
    LogClass* log = iter->getLogger();
    log->updateFileP(m_coins, m_HP, iter->getX(), iter->getY());
    while(1){
        if((iter->getValue() == CellTypes::EXIT) && (m_coins >= 10)){
            break;
        }
        std::cout << *this;
        std::cout << *iter->getObj();
        
        std::cin >> route;
        if(route == "s"){
            iter->down();
        }else if(route == "w"){
            iter->up();
        }else if(route == "a"){
            iter->left();
        }else if(route == "d"){
            iter->right();
        }else if(route == "e"){
           this->doIt();
           continue;
        }else{
            continue;
        }
        log->updateFileP(m_coins, m_HP, iter->getX(), iter->getY());
    }
}

void Player::doIt(){
    Cell* objValue = iter->getObj();
    if(objValue->getObj()){
        iter->getLogger()->updateFileP(iter->getX(), iter->getY(), objValue->getObj());
        if(objValue->getObj()->WhatAreYou() == CellTypes::WELL){
            this->setUseStrategy(new WellUse);
        }else if(objValue->getObj()->WhatAreYou() == CellTypes::BUSH){
            this->setUseStrategy(new BushUse);
        }else if(objValue->getObj()->WhatAreYou() == CellTypes::SNOWMAN){
            this->setUseStrategy(new SnowmanUse);
        }
    m_coins += usingStrategy->use();
    objValue->reObj(nullptr);
    this->setUseStrategy(nullptr);
    }

}

void Player::setUseStrategy(IUsing* newUsingStrategy){
    delete usingStrategy;
    usingStrategy = newUsingStrategy;
}

std::ostream& operator<< (std::ostream &out, const Player &P1){
    P1.iter->result();
    out << "У игрока в наличии " << P1.m_coins << " монеток и " << P1.m_HP << " ХП.\nКоординаты: ( " << P1.iter->getY() + 1 << ";" << P1.iter->getX() + 1 << " )\n";
    return out; 
}

std::ofstream& operator<< (std::ofstream &out, const Player &P1){
    out << "У игрока в наличии " << P1.m_coins << " монеток и " << P1.m_HP << " ХП.\nКоординаты: ( " << (P1.iter->getY() + 1) << ";" << (P1.iter->getX() + 1) << " )\n";
    return out; 
}