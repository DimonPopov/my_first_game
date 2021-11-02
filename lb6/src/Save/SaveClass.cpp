#include "SaveClass.h"
#include "../Map/Cell.h"
#include "../Enemy/Enemy1.h"
#include "../Enemy/Enemy2.h"
#include "../Enemy/Enemy3.h"



void SaveClass::saving(std::shared_ptr<Player> player, std::shared_ptr<Map> map, std::shared_ptr<IEnemy> e1, std::shared_ptr<IEnemy> e2, std::shared_ptr<IEnemy> e3){
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    char s[40];
    strftime(s, 40, "SaveFile.txt", timeinfo);
    fileName = s;
    saveFile.open(fileName);
    saveFile << map->getWidth() << ' ' << map->getHeight() << '\n';
    for(size_t i = 0; i < map->getWidth(); i++){
        for(size_t j = 0; j < map->getHeight(); j++){
            saveFile << map->getCellValue(j,i);
        }
        saveFile << '\n';
    }
    saveFile << player->getHP() << ' ' << player->getCoins() << ' ' << player->myPositionX() << ' ' << player->myPositionY() << '\n';
    saveFile << e1->getPositionX() << ' ' << e1->getPositionY() << '\n';
    saveFile << e2->getPositionX() << ' ' << e2->getPositionY() << '\n';
    saveFile << e3->getPositionX() << ' ' << e3->getPositionY() << '\n';
}



void SaveClass::loading(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map, std::shared_ptr<Enemy1> &e1, std::shared_ptr<Enemy2> &e2, std::shared_ptr<Enemy3> &e3){
    try{    
        std::ifstream inp("SaveFile.txt");
        if(!inp){
            throw "Не может быть открыт на чтение!";
        }
        std::string g{};
        char x;
        char y;
        char value;
        inp >> x;
        inp >> y;
        if(static_cast<int>(y)-'0' >= 10 || !isdigit(y)){
            throw "Ширина поля больше 10";
        }
        if(static_cast<int>(x)-'0' >= 10 || !isdigit(x)){
            throw "Высота поля больше 10";
        }
        //std:: cout << static_cast<int>(y)-'0' << ' ' << static_cast<int>(x)-'0' << '\n';
        map = Map::getInstance(static_cast<int>(x)-'0', static_cast<int>(y)-'0');
        for(size_t i = 0; i < map->m_height; i++){
            for(size_t j = 0; j < map->m_width; j++){
                inp >> value;
                if(static_cast<int>(value)-'0' > CellTypes::MAX || !isdigit(value)){
                    throw "Не верное значение клетки";
                }
                map->m_arrField[j][i].reValue(static_cast<int>(value)-'0');
                
            }
            std::cout << '\n';
        }
        player = std::make_shared<Player>();
        inp >> x;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' <= 0  || !isdigit(x) ){
            throw "Не корректный показатель здоровья";
        }
        player->m_HP = static_cast<int>(x)-'0';
        inp >> x;
        if(static_cast<int>(x)-'0' <= 0  || !isdigit(x) ){
            throw "Не корректный показатель монет";
        }
        player->m_coins = static_cast<int>(x)-'0';
        inp >> x;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция по X";
        }
        player->playerIter->m_positionX = static_cast<int>(x)-'0';
        inp >> x;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция по Y";
        }
        player->playerIter->m_positionY = static_cast<int>(x)-'0';
        //std::cout << player->m_HP << ' ' << player->m_coins << ' ' << player->playerIter->m_positionX << ' ' << player->playerIter->m_positionY << '\n';
        inp >> x;
        inp >> y;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по X";
        }
        if(static_cast<int>(y)-'0' >= 10 || static_cast<int>(y)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по Y";
        }
        e1 = std::make_shared<Enemy1>();
        e1->behavior->newPosition(static_cast<int>(x)-'0',static_cast<int>(y)-'0');
        inp >> x;
        inp >> y;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по X";
        }
        if(static_cast<int>(y)-'0' >= 10 || static_cast<int>(y)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по Y";
        }
        e2 = std::make_shared<Enemy2>();
        e2->behavior->newPosition(static_cast<int>(x)-'0',static_cast<int>(y)-'0');
        inp >> x;
        inp >> y;
        if(static_cast<int>(x)-'0' >= 10 || static_cast<int>(x)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по X";
        }
        if(static_cast<int>(y)-'0' >= 10 || static_cast<int>(y)-'0' < 0  || !isdigit(x) ){
            throw "Не корректная позиция противника по Y";
        }
        e3 = std::make_shared<Enemy3>();
        e3->behavior->newPosition(static_cast<int>(x)-'0',static_cast<int>(y)-'0');
    }catch(const char* err){
        std::cerr << err << '\n';
        exit(1);
    }
}