#pragma once

#include "../ClasesForProject/Cell.h"
#include <string>



class IElements{
public:
    virtual ~IElements(){}
    virtual int WhatAreYou() = 0;
    virtual std::string whatName() = 0;
};