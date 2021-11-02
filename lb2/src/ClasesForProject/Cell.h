#pragma once

#include "../Elements/IElements.h"



class IElements;

namespace CellTypes{
    enum CellState{
        OPEN, START, EXIT, CLOSE, WELL, BUSH, SNOWMAN
    };
}

class Cell{
    IElements* object;
    int m_value;        //Значение клетки
public:
    Cell();
    ~Cell();
    int getValue();
    void reValue(int newValue);
    IElements* getObj();
    void reObj(IElements* newObj);
};