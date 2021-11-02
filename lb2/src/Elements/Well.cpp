#include "Well.h"

#include <iostream>



Well::Well(){
    WhoAmI = CellTypes::WELL;
}

Well::~Well(){
    
}

void Well::inspect(){
    std::cout << "Одинокий колодец" << "\n";
}

int Well::WhatAreYou(){
    return WhoAmI;
}