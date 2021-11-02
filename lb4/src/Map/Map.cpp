#include "Map.h"
#include "Cell.h"

#include "../Elements/Factory/Factory1.h"
#include "../LogClass/LogClass.h"
#include "../Enum/CellAndElemENUM.h"

#include <iostream>
#include <ctime>


std::shared_ptr<Map> Map::m_ptrMap = nullptr;

std::shared_ptr<Map> Map::getInstance(const unsigned width, const unsigned height){
    if(m_ptrMap == nullptr){
        std::shared_ptr<Map> m(new Map(width, height));
        m_ptrMap = m;
    }
    return m_ptrMap;
}



std::shared_ptr<Map> Map::getInstance(){
    if(m_ptrMap == nullptr){
        std::shared_ptr<Map> m(new Map(7, 7));
        m_ptrMap = m;
    }

    return m_ptrMap;
}



Map::Map(unsigned width, unsigned height):m_width(width), m_height(height){     //Карта будет статичной?

    m_arrField = std::make_unique<std::unique_ptr<Cell[]>[]>(m_width);

    logger = std::make_shared<LogClass>();

    for(size_t i = 0; i < m_width; i++){
        m_arrField[i] = std::make_unique<Cell[]>(m_height);
    }

    std::unique_ptr<IFactory> fact = std::make_unique<Factory1>();

    m_arrField[0][0].reValue(CellTypes::START);
    m_arrField[m_width - 1][m_height - 1].reValue(CellTypes::EXIT);

    srand(time(nullptr));
    unsigned counterOfClosedBlocks = 0;
    while (counterOfClosedBlocks < m_width && counterOfClosedBlocks < m_height) {
        unsigned x = rand() % m_height;
        unsigned y = rand() % m_width;
        if ((x != 0 || y != 0) && (x != m_width - 1 || y != m_height - 1) && (x != y)) {
            m_arrField[x][y].reValue(CellTypes::CLOSE);
            counterOfClosedBlocks++;
        }
    }
    unsigned counterElements = 0;
    while(counterElements < (m_height * m_width) / 10){
        unsigned x = rand() % m_height;
        unsigned y = rand() % m_width;
        if((x != 0 || y != 0) && (x != m_width - 1 || y != m_height - 1) && (x != y) && m_arrField[x][y].getValue() == CellTypes::OPEN){
            std::shared_ptr<IElements> obj = fact->createElement();
            logger->logElement(obj, x, y);
            m_arrField[x][y].reObj(obj);
            counterElements++;
        }
    }

}



unsigned Map::getWidth(){ return m_width; }



unsigned Map::getHeight(){ return m_height; }



unsigned Map::getCellValue(const unsigned x, const unsigned y){
    return m_arrField[x][y].getValue();
}



std::shared_ptr<LogClass> Map::getLogger(){
    return logger;
}