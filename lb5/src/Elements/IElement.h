#pragma once

#include <string>



class IElements{
public:
    virtual int WhatAreYou() = 0;
    virtual std::string whatName() = 0;
    virtual int giveMeCoints() = 0;
};