#include "Cell.h"
#include "../Enum/CellAndElemENUM.h"



Cell::Cell():m_value(CellTypes::OPEN){
    object = nullptr;
}

int Cell::getValue(){
    return m_value;
}

void Cell::reValue(int newValue){
    m_value = newValue;
}


void Cell::reObj(std::shared_ptr<IElements> newObj){

    object = newObj;

    if(object){
        if(object->WhatAreYou() == CellTypes::OBJ1){
            m_value = CellTypes::OBJ1;
        }else if(object->WhatAreYou() == CellTypes::OBJ2){
            m_value = CellTypes::OBJ2;
        }else if(object->WhatAreYou() == CellTypes::OBJ3){
            m_value = CellTypes::OBJ3;
        }else{
            m_value = CellTypes::OPEN;
        }
    }else{
        m_value = CellTypes::OPEN;
    }
    
}



std::shared_ptr<IElements> Cell::getObj(){ return object; }