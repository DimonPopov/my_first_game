#pragma once 

#include "IElement.h"
#include <fstream>



class Obj1: public IElements{
    unsigned WhoAmI;
    std::string myName;
    int coint;
    int countOfUses;
public:
    Obj1();
    int WhatAreYou();
    std::string whatName();
    int giveMeCoints();
    friend std::ostream& operator<< (std::ostream &out, const Obj1 &obj);
    friend std::ofstream& operator<< (std::ofstream &out, const Obj1 &obj);
};



class Obj2: public IElements{
    unsigned WhoAmI;
    std::string myName;
    int coint;
    int countOfUses;
public:
    Obj2();
    int WhatAreYou();
    std::string whatName();
    int giveMeCoints();
    friend std::ostream& operator<< (std::ostream &out, const Obj2 &obj);
    friend std::ofstream& operator<< (std::ofstream &out, const Obj2 &obj);
};



class Obj3: public IElements{
    unsigned WhoAmI;
    std::string myName;
    int coint;
    int countOfUses;
public:
    Obj3();
    int WhatAreYou();
    std::string whatName();
    int giveMeCoints();
    friend std::ostream& operator<< (std::ostream &out, const Obj3 &obj);
    friend std::ofstream& operator<< (std::ofstream &out, const Obj3 &obj);
};