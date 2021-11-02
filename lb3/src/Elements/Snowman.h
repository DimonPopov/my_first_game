#pragma once 

#include "IElements.h"



class Snowman: public IElements{
    int WhoAmI;
    std::string myName;
public:
    Snowman();
    ~Snowman();
    int WhatAreYou();
    std::string whatName();
};