#include "Cell.h"

#include "../Elements/Factory/BushFactory.h"
#include "../Elements/Factory/SnowmanFactory.h"
#include "../Elements/Factory/WellFactory.h"



Cell::Cell():m_value(CellTypes::OPEN){
    object = nullptr;
}

Cell::~Cell(){
    if(object){
        delete object;
    }
}

int Cell::getValue(){
    return m_value;
}

IElements* Cell::getObj(){
    return object;
}

void Cell::reValue(int newValue){
    m_value = newValue;
}

void Cell::reObj(IElements* newObj){

    if(object){
        delete object;
    }

    object = newObj;

    if(object){
        if(object->WhatAreYou() == CellTypes::BUSH){
            m_value = CellTypes::BUSH;
        }else if(object->WhatAreYou() == CellTypes::SNOWMAN){
            m_value = CellTypes::SNOWMAN;
        }else if(object->WhatAreYou() == CellTypes::WELL){
            m_value = CellTypes::WELL;
        }else{
            m_value = CellTypes::OPEN;
        }
    }else{
        m_value = CellTypes::OPEN;
    }
}

std::ostream& operator<< (std::ostream &out, const Cell &cell){
    if(cell.object){
        out << cell.object->whatName() << '\n';
    }else{
        out << "Пусто.\n";
    }
    return out; 
}