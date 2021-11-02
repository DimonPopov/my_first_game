#include "LogClass.h"
#include "../Player/Player.h"



LogClass::LogClass(){
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    char s[40];
    strftime(s, 40, "log_%F_%T.log", timeinfo);
    fileName = s;
    logFile.open(fileName);
    logFile << "Start game\n";
    std::cout << "Start game\n";
}

LogClass::~LogClass(){
    logFile << "End game\n";
    std::cout << "End game\n";
    logFile.close();
}

std::string LogClass::writeLog(){
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    char s[30];
    strftime(s, 30, "log_%F_%T.log: ", timeinfo);
    std::string logString = s;
    return logString;
}

void LogClass::logPlayer(Player* player){
    logFile << this->writeLog() << *player;
    std::cout << this->writeLog() << *player;
}

void LogClass::logElement(std::shared_ptr<IElements> obj, unsigned x, unsigned y){  // Fucking koctil'
    logFile << this->writeLog() << "Объект " << obj->whatName() << " создан по координатам: ( " << x << ':' << y << " )" << '\n';
    std::cout << this->writeLog() << "Объект " << obj->whatName() << " создан по координатам: ( " << x << ':' << y << " )" << '\n';
}