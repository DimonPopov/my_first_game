#pragma once

#include "IFactory.h"



class WellFactory: public IFactory{
public:
    IElements* createElement();
};