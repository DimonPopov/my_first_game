#pragma once

#include "IBehavior.h"
#include "../Enemy1.h"
#include "../../Iterator/Iterator.h"
#include "../../Enum/CellAndElemENUM.h"



class Aggressive: public IBehavior{
    std::unique_ptr<Iterator> iter;
public:
    Aggressive();
    void move(unsigned x, unsigned y);
    unsigned getX();
    unsigned getY();
    void newPosition(unsigned x, unsigned y);
};



class Neutral: public IBehavior{
    std::unique_ptr<Iterator> iter;
public:
    Neutral();
    void move(unsigned x, unsigned y);
    unsigned getX();
    unsigned getY();
    void newPosition(unsigned x, unsigned y);
};



class Passive: public IBehavior{
    std::unique_ptr<Iterator> iter;
public:
    Passive();
    void move(unsigned x, unsigned y);
    unsigned getX();
    unsigned getY();
    void newPosition(unsigned x, unsigned y);
};