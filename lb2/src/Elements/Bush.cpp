#include "Bush.h"

#include <iostream>



Bush::Bush(){
    WhoAmI = CellTypes::BUSH;
}

Bush::~Bush(){

}

void Bush::inspect(){
    std::cout << "Просто парочка кустиков с малиной" << "\n";
}

int Bush::WhatAreYou(){
    return WhoAmI;
}
