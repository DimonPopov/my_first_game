#pragma once 

#include "IElements.h"



class Snowman: public IElements{
    int WhoAmI;
    int count;
public:
    Snowman();
    ~Snowman();
    void inspect();
    int WhatAreYou();
};