#include "Player.h"
#include "../Enum/CellAndElemENUM.h"
#include "../Iterator/Iterator.h"
#include "Strategy/Using.h"
#include "../LogClass/LogClass.h"
#include "../Map/Map.h"

#include <iostream>




Player::Player():m_HP(9), m_coins(0){
    playerIter = std::make_unique<Iterator>(PlayerOrEnemy::IamPLAYER);
    usingStrategy = nullptr;
}

unsigned Player::myPositionX(){ return playerIter->getX(); }

unsigned Player::myPositionY(){ return playerIter->getY(); }

int Player::getHP(){ return m_HP; }

int Player::getCoins(){ return m_coins; }

void Player::move(std::string route){ 

    std::shared_ptr<LogClass> log = Map::getInstance()->getLogger();

    if(route == "down"){
        playerIter->down();
    }else if(route == "up"){
        playerIter->up();
    }else if(route == "left"){
        playerIter->left();
    }else if(route == "right"){
        playerIter->right();
    }else if(route == "use"){
        this->use();
    }

    log->logPlayer(this);
}


void Player::use(){

    std::shared_ptr<IElements> obj = playerIter->getObj();
    if(obj){
        //iter->getLogger()->updateFileP(iter->getX(), iter->getY(), objValue->getObj());
        if(obj->WhatAreYou() == CellTypes::OBJ1){
            usingStrategy = std::make_unique<UseObj1>();
        }else if(obj->WhatAreYou() == CellTypes::OBJ2){
            this->setUseStrategy(std::unique_ptr<UseObj1>());
        }else if(obj->WhatAreYou() == CellTypes::OBJ3){
            this->setUseStrategy(std::unique_ptr<UseObj1>());
        }
        usingStrategy->use();
        m_coins = *this + obj;
        obj = nullptr;
        this->setUseStrategy(nullptr);
    }

}

void Player::use(std::shared_ptr<IEnemy> enemy){
    m_HP = *this + enemy;

}

void Player::setUseStrategy(std::unique_ptr<IUsing> newUsingStrategy){
    usingStrategy = std::move(newUsingStrategy);
}



int Player::operator+(std::shared_ptr<IElements> obj) const{
    return m_coins + obj->giveMeCoints();
}



int Player::operator+(std::shared_ptr<IEnemy> enemy){
    return this->m_HP + enemy->giveMeAt();
}


std::ostream& operator<< (std::ostream &out, const Player &P1){
    out << "У игрока в наличии " << P1.m_coins << " монеток и " << P1.m_HP << " ХП.\nКоординаты: ( " << P1.playerIter->getY() + 1 << ";" << P1.playerIter->getX() + 1 << " )\n";
    return out; 
}

std::ofstream& operator<< (std::ofstream &out, const Player &P1){
    out << "У игрока в наличии " << P1.m_coins << " монеток и " << P1.m_HP << " ХП.\nКоординаты: ( " << (P1.playerIter->getY() + 1) << ";" << (P1.playerIter->getX() + 1) << " )\n";
    return out; 
}