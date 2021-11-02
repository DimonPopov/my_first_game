#include "Well.h"

#include <iostream>



Well::Well(){
    WhoAmI = CellTypes::WELL;
    myName = "Well";
}

Well::~Well(){
    
}

int Well::WhatAreYou(){
    return WhoAmI;
}

std::string Well::whatName(){
    return myName;
}