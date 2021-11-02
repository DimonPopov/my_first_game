#pragma once

#include "IElements.h"



class Well: public IElements{
    int WhoAmI;
    int count;
public:
    Well();
    ~Well();
    void inspect();
    int WhatAreYou();
};