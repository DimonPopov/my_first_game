#include "./ClasesForProject/Map.h"
#include "./ClasesForProject/Map_Iterator.h"    
#include <memory>
#include <iostream>
#include <string>

int main(){
    
    using namespace std;

    //Умные указатели
    unique_ptr<Map> field(Map::getInstance(5,5));
    unique_ptr<Map_Iterator> iter(new Map_Iterator(Map::getInstance()));

    //Строка для хранения наших команд
    string route;

    //Проверка работоспособности

    while(iter->getValue() != 2){
        iter->result();
        cout << "Куда?" << "\n";
        cin >> route;
        if(route == "d"){
            iter->down();
        }
        if(route == "u"){
            iter->up();
        }
        if(route == "l"){
            iter->left();
        }
        if(route == "r"){
            iter->right();
        }
        
        if(route == "g"){
            cout << iter->getValue() << "\n";
        }
    }
    cout << "you win!" << "\n";

    return 0;
}