#pragma once 

#include "IElements.h"




class Bush: public IElements{
    int WhoAmI;     // Номер объекта
    int count;      // Кол-во взаимодействий
public:
    Bush();
    ~Bush();
    void inspect();
    int WhatAreYou();
};