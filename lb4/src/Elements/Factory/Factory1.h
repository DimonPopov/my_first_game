#pragma once

#include "IFactory.h"
#include "../IElement.h"



class Factory1: public IFactory{
public:
    std::shared_ptr<IElements> createElement();
};