#pragma once

#include <string>

class IBehavior{
public:
    virtual void move(unsigned x, unsigned y) = 0;
    virtual unsigned getX() = 0;
    virtual unsigned getY() = 0;
};