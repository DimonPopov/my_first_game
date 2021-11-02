#pragma once

namespace CellTypes{
    enum CellState{
        OPEN, START, EXIT, CLOSE
    };
}

class Cell{
    int m_value;        //Значение клетки
public:
    Cell();
    Cell(int);
    int getValue();
    void reValue(int);
};