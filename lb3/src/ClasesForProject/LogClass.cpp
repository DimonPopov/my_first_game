#include "LogClass.h"
#include "Player.h"

LogClass::LogClass(){
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    char s[40];
    strftime(s, 40, "log_%F_%T.log",timeinfo);
    fileName = s;
    logFile.open(fileName);
    logFile << "Start game\n";
}

LogClass::~LogClass(){
    logFile << "End game\n";
    logFile.close();
}

std::string LogClass::writeLog(){
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    char s[30];
    strftime(s, 30, "log_%F_%T.log",timeinfo);
    std::string logString = s;
    return logString;
}

void LogClass::updateFileP(int coins, int hp, int x, int y){
    logFile << this->writeLog() << ": " << "У игрока в наличии " << coins << " монеток и " << hp << " HP" << "; Координаты: ( " << x + 1 << ';' << y + 1 << " )\n";
}

void LogClass::updateFileP(int x, int y, IElements* obj){
    logFile << this->writeLog() <<": " << "Игрок взаимодействует с " << obj->whatName() << " по координатам ( " << x + 1 << ';' << y + 1 << " )\n";
}

void LogClass::updateFileE(int x, int y, IElements* obj){
    logFile << this->writeLog() <<": " << "Создан элемент " << obj->whatName() << " по координатам ( " << x + 1 << ';' << y + 1 << " )\n";
}