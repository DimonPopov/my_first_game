#pragma once

#include <string>
#include <memory>
#include "./Behavior/IBehavior.h"

class IEnemy{
public:
    virtual void behaviorMove(unsigned x, unsigned y) = 0;
    virtual void setBehavior(std::shared_ptr<IBehavior> newBehavior) = 0;
    virtual unsigned getPositionX() = 0;
    virtual unsigned getPositionY() = 0;
    virtual int giveMeAt() = 0;
};