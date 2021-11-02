#pragma once

#include <string>
#include <memory>

class IBehavior{
public:
    virtual void move(unsigned x, unsigned y) = 0;
    virtual unsigned getX() = 0;
    virtual unsigned getY() = 0;
    virtual void newPosition(unsigned x, unsigned y) = 0;
};