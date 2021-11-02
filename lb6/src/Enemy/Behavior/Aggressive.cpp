#include "Behavior.h"
#include "../../Player/Player.h"

#include <memory>
#include <iostream>




Aggressive::Aggressive(){
    iter = std::make_unique<Iterator>(PlayerOrEnemy::IamENEMY);
}



unsigned Aggressive::getX(){
    return iter->m_positionX;
}



unsigned Aggressive::getY(){
    return iter->m_positionY;
}



void Aggressive::move(unsigned x, unsigned y){

    if(iter->m_positionY < y){
        iter->down();
    }else if(iter->m_positionY > y){
        iter->up();
    }else if(iter->m_positionY == y){
        if(iter->m_positionX > x){
            iter->left();
        }else if(iter->m_positionX < x){
            iter->right();
        }
    }

}


void Aggressive::newPosition(unsigned x, unsigned y){
    iter->m_positionX = x;
    iter->m_positionY = y;
}