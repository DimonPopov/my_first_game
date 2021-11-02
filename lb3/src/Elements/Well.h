#pragma once

#include "IElements.h"



class Well: public IElements{
    int WhoAmI;
    std::string myName;
public:
    Well();
    ~Well();
    int WhatAreYou();
    std::string whatName();
};