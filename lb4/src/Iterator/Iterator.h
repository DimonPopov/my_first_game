#pragma once

#include <memory>
#include "../Elements/IElement.h"
#include "../Elements/Object.h"



class Map;
class Cell;

class Iterator{
    std::shared_ptr<Map> stc;
public:
    unsigned m_positionX;
    unsigned m_positionY;
    Iterator(int whoAreYou);
    void up();
    void down();
    void left();
    void right();
    unsigned getX();
    unsigned getY();
    unsigned getValue();
    std::shared_ptr<IElements> getObj();
    
};
