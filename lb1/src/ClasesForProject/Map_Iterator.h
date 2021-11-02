#pragma once

class Map;

class Map_Iterator{
    const Map *stc;
    int m_positionX;
    int m_positionY;
public:
    Map_Iterator(const Map*);
    //~Map_Iterator();
    void up();
    void down();
    void left();
    void right();
    int getValue();
    void result();
};