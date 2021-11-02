#pragma once

class Map;
class IElements;
class Cell;
class LogClass;


class Map_Iterator{
    const Map *stc;
    int m_positionX;
    int m_positionY;
public:
    Map_Iterator();
    void up();
    void down();
    void left();
    void right();
    int getValue();
    int getX();
    int getY();
    Cell* getObj();
    LogClass* getLogger();
    void result();
};