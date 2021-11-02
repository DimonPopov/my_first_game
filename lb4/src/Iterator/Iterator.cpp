
#include "Iterator.h"

#include "../Map/Cell.h"
#include "../Map/Map.h"
#include "../Enum/CellAndElemENUM.h"

#include <iostream>



Iterator::Iterator(int whoAreYou){
    stc = Map::getInstance();
    if(whoAreYou == PlayerOrEnemy::IamPLAYER){
        for(size_t i = 0; i < stc->m_width; i++){
            for(size_t j = 0; j < stc->m_height; j++){
                if(stc->m_arrField[i][j].getValue() == CellTypes::START){
                    m_positionX = i;
                    m_positionY = j;
                }
            }
        }
    }
    if(whoAreYou == PlayerOrEnemy::IamENEMY){

    }
}

void Iterator::left(){
    if(m_positionX > 0){
        if(stc->m_arrField[m_positionX - 1][m_positionY].getValue() != CellTypes::CLOSE){
            m_positionX--;
        }
    }
}

void Iterator::right(){
    if((m_positionX + 1) < stc->m_width){
        if(stc->m_arrField[m_positionX + 1][m_positionY].getValue() != CellTypes::CLOSE){
            m_positionX++;
        }
    }
}

void Iterator::down(){
    if((m_positionY + 1) < stc->m_height){
        if(stc->m_arrField[m_positionX][m_positionY + 1].getValue() != CellTypes::CLOSE){
            m_positionY++;
        }
    }
}

void Iterator::up(){
    if(m_positionY > 0){
        if(stc->m_arrField[m_positionX][m_positionY - 1].getValue() != CellTypes::CLOSE){
            m_positionY--;
        }
    }
}

unsigned Iterator::getValue(){ return stc->m_arrField[m_positionX][m_positionY].getValue(); }

unsigned Iterator::getX(){ return m_positionX; }

unsigned Iterator::getY(){ return m_positionY; }

std::shared_ptr<IElements> Iterator::getObj(){      // fucking koctil'
    std::shared_ptr<IElements> tmp = stc->m_arrField[m_positionX][m_positionY].getObj();
    if(tmp){
        stc->m_arrField[m_positionX][m_positionY].reObj(nullptr);
    }
    return tmp;
    }