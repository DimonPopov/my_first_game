#include "Map_Iterator.h"
#include "Cell.h"
#include "Map.h"
#include <iostream>

class Map_Iterator;

Map_Iterator::Map_Iterator(const Map *s){
    stc = s;
    for(int i = 0; i < s->m_width; i++){
        for(int j = 0; j < s->m_height; j++){
            if(s->m_arrField[i][j].getValue() == CellTypes::START){
                m_positionX = i;
                m_positionY = j;
            }
        }
    }
}

//Map_Iterator::~Map_Iterator(){}

void Map_Iterator::up(){
    if(m_positionX > 0){
        if(stc->m_arrField[m_positionX - 1][m_positionY].getValue() != CellTypes::CLOSE){
            m_positionX--;
        }
    }
}

void Map_Iterator::down(){
    if((m_positionX + 1) < stc->m_width){
        if(stc->m_arrField[m_positionX + 1][m_positionY].getValue() != CellTypes::CLOSE){
            m_positionX++;
        }
    }
}

void Map_Iterator::right(){
    if((m_positionY + 1) < stc->m_height){
        if(stc->m_arrField[m_positionX][m_positionY + 1].getValue() != CellTypes::CLOSE){
            m_positionY++;
        }
    }
}

void Map_Iterator::left(){
    if(m_positionY > 0){
        if(stc->m_arrField[m_positionX][m_positionY - 1].getValue() != CellTypes::CLOSE){
            m_positionY--;
        }
    }
}

int Map_Iterator::getValue(){
    return stc->m_arrField[m_positionX][m_positionY].getValue();
}

void Map_Iterator::result(){
    for(int i = 0; i < stc->m_width; i++){
        for(int j = 0; j < stc->m_height; j++){
            if((i == m_positionX) && (j == m_positionY)){
                std::cout << "+ ";
            }else{
                std::cout << stc->m_arrField[i][j].getValue() << " ";
            }
        }
        std::cout << "\n";
    }         
}