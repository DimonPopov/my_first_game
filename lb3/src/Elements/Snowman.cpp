#include "Snowman.h"

#include <iostream>

Snowman::Snowman(){

    WhoAmI = CellTypes::SNOWMAN;
    myName = "Snowman";
}

Snowman::~Snowman(){
    
}

int Snowman::WhatAreYou(){
    return WhoAmI;
}

std::string Snowman::whatName(){
    return myName;
}