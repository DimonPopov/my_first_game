#include "Snowman.h"

#include <iostream>

Snowman::Snowman(){

    WhoAmI = CellTypes::SNOWMAN;
}

Snowman::~Snowman(){
    
}

void Snowman::inspect(){
    std::cout << "Устрашающий снеговик" << "\n";
}

int Snowman::WhatAreYou(){
    return WhoAmI;
}