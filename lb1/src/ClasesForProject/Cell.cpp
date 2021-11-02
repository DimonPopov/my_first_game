#include "Cell.h"

Cell::Cell():m_value(CellTypes::OPEN){}
Cell::Cell(int a):m_value(a){}

int Cell::getValue(){
    return m_value;
}

void Cell::reValue(int newValue){
    m_value = newValue;
}