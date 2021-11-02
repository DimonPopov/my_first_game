#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "../Elements/IElements.h"



class Player;

class LogClass{
    std::ofstream logFile;
    std::string fileName;
public:
    LogClass();
    ~LogClass();
    std::string writeLog();
    void updateFileP(int, int, int, int);
    void updateFileP(int, int, IElements*);
    void updateFileE(int, int, IElements*);
};