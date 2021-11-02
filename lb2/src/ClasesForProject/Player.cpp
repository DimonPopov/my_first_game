#include "Player.h"
#include "Map_Iterator.h"
#include "../Elements/IElements.h"
#include "./UseStrategy/IUsing.h"
#include "./UseStrategy/SnowmanUse.h"
#include "./UseStrategy/WellUse.h"
#include "./UseStrategy/BushUse.h"
#include "Cell.h"
#include "Map.h"

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

    while(1){
        if((iter->getValue() == CellTypes::EXIT) && (m_coins >= 10)){
            break;
        }
        iter->result();
        std::cout << m_coins << '\n';
        std::cin >> route;
        if(route == "s"){
            iter->down();
        }
        if(route == "w"){
            iter->up();
        }
        if(route == "a"){
            iter->left();
        }
        if(route == "d"){
            iter->right();
        }
        if(route == "e"){
           this->doIt(iter->getObj());
        }
        if(route == "q"){
            this->inspect(iter->getValue());
        }
    }
}

void Player::doIt(Cell* objValue){
    if(objValue->getObj()){
        if(objValue->getObj()->WhatAreYou() == CellTypes::WELL){
            this->setUseStrategy(new WellUse);
        }else if(objValue->getObj()->WhatAreYou() == CellTypes::BUSH){
            this->setUseStrategy(new BushUse);
        }else if(objValue->getObj()->WhatAreYou() == CellTypes::SNOWMAN){
            this->setUseStrategy(new SnowmanUse);
        }
    m_coins += usingStrategy->use();
    objValue->reObj(nullptr);
    //objValue->reValue(CellTypes::OPEN);
    this->setUseStrategy(nullptr);
    }

}

void Player::inspect(int objValue){
    if(objValue == CellTypes::BUSH){
        std::cout << "Это куст\n";
    }else if(objValue == CellTypes::SNOWMAN){
        std::cout << "Это Снеговик\n";
    }else if(objValue == CellTypes::WELL){
        std::cout << "Это Колодец\n";
    }else if(objValue == CellTypes::OPEN){
        std::cout << "Тут ничего нет\n";
    }else if(objValue == CellTypes::START){
        std::cout << "Тут я появился\n";
    }else if(objValue == CellTypes::EXIT){
        std::cout << "Тут у нас выход\n";
    }
}

void Player::setUseStrategy(IUsing* newUsingStrategy){
    delete usingStrategy;
    usingStrategy = newUsingStrategy;
}