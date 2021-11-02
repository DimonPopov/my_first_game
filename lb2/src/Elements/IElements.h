#pragma once

#include "/home/l2d/Рабочий стол/source/FIacko/labs/OOP_3sem/3_sem_lb2/src/ClasesForProject/Cell.h"


class IElements{
public:
    virtual ~IElements(){}
    virtual void inspect() = 0;
    virtual int WhatAreYou() = 0;
};