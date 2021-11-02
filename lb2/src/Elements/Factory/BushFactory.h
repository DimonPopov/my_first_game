#pragma once

#include "IFactory.h"



class BushFactory: public IFactory{
public:
    IElements* createElement();
};