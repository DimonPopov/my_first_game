#pragma once 

#include "IElements.h"



class Bush: public IElements{
    int WhoAmI;     // Номер объекта
    std::string myName;
public:
    Bush();
    ~Bush();
    int WhatAreYou();
    std::string whatName();
};