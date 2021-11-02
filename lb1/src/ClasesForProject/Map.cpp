#include "Map.h"
#include "Cell.h"
#include "Map_Iterator.h"


Map* Map::m_ptrMap = nullptr;

Map* Map::getInstance(){
    if(m_ptrMap == nullptr){
        m_ptrMap = new Map();
    }
    return m_ptrMap;
}

Map* Map::getInstance(int sizeX, int sizeY){
    if(m_ptrMap == nullptr){
        m_ptrMap = new Map(sizeX, sizeY);
    }
    return m_ptrMap;
}

Map::Map():m_width(5), m_height(5){     //Карта будет статичной?
    m_arrField = new Cell*[m_width];
    for(int i = 0; i < m_width; i++){
        m_arrField[i] = new Cell[m_height];
    }
    m_arrField[0][0].reValue(CellTypes::START);
    m_arrField[m_width - 1][m_height - 1].reValue(CellTypes::EXIT);
}

Map::Map(int sizeX, int sizeY):m_width(sizeX), m_height(sizeY){
    m_arrField = new Cell*[m_width];
    for(int i = 0; i < m_width; i++){
        m_arrField[i] = new Cell[m_height];
    }
    m_arrField[0][0].reValue(CellTypes::START);
    m_arrField[m_width - 1][m_height - 1].reValue(CellTypes::EXIT);
}

Map::~Map(){
    for(int i = 0; i < m_width; i++){
        delete[] m_arrField[i];
    }
    delete[] m_arrField;
}

Map_Iterator* Map::createIterator() const{
    return new Map_Iterator(this);
}