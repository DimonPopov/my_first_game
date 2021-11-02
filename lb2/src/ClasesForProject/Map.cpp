#include "Map.h"
#include "Cell.h"
#include "Map_Iterator.h"
#include "../Elements/Bush.h"
#include "../Elements/Snowman.h"
#include "../Elements/Well.h"
#include "../Elements/Factory/BushFactory.h"
#include "../Elements/Factory/SnowmanFactory.h"
#include "../Elements/Factory/WellFactory.h"


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

    WellFactory fact1;
    BushFactory fact2;
    SnowmanFactory fact3;

    m_arrField[0][1].reObj(fact1.createElement());
    m_arrField[0][2].reObj(fact2.createElement());
    m_arrField[0][3].reObj(fact3.createElement());
}

Map::Map(int sizeX, int sizeY):m_width(sizeX), m_height(sizeY){
    m_arrField = new Cell*[m_width];
    for(int i = 0; i < m_width; i++){
        m_arrField[i] = new Cell[m_height];
    }
    

    // Размещение объектов на поле

    WellFactory fact1;
    BushFactory fact2;
    SnowmanFactory fact3;

    m_arrField[8][8].reValue(CellTypes::CLOSE);
    m_arrField[0][9].reValue(CellTypes::CLOSE);
    m_arrField[5][6].reValue(CellTypes::CLOSE);
    m_arrField[2][4].reValue(CellTypes::CLOSE);
    m_arrField[4][2].reValue(CellTypes::CLOSE);
    m_arrField[9][0].reValue(CellTypes::CLOSE);
    m_arrField[7][7].reValue(CellTypes::CLOSE);

    m_arrField[2][2].reObj(fact1.createElement());
    m_arrField[3][3].reObj(fact2.createElement());
    m_arrField[4][4].reObj(fact3.createElement());

    m_arrField[0][0].reValue(CellTypes::START);
    m_arrField[m_width - 1][m_height - 1].reValue(CellTypes::EXIT);
}

Map::~Map(){
    for(int i = 0; i < m_width; i++){
        delete[] m_arrField[i];
    }
    delete[] m_arrField;

}