#pragma once

#include "IFactory.h"



class SnowmanFactory: public IFactory{
public:
    IElements* createElement();
};