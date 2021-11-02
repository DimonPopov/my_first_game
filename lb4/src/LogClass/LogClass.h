#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <memory>

#include "../Elements/IElement.h"
#include "../Elements/Object.h"

class Player;

class LogClass{
    std::ofstream logFile;
    std::string fileName;
    std::string writeLog();
public:
    LogClass();
    ~LogClass();
    void logPlayer(Player*);
    void logElement(std::shared_ptr<IElements>, unsigned, unsigned);
};