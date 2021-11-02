#include "Bush.h"

#include <iostream>



Bush::Bush(){
    WhoAmI = CellTypes::BUSH;
    myName = "Bush";
}

Bush::~Bush(){

}

int Bush::WhatAreYou(){
    return WhoAmI;
}

std::string Bush::whatName(){
    return myName;
}
