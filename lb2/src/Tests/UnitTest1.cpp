#include <iostream>
#include "../ClasesForProject/Map.h"
#include "../ClasesForProject/Cell.h"
#include "../ClasesForProject/Map_Iterator.h" 
#include "UnitTest.h"

using namespace std;
using namespace CellTypes;


int main(){

    cout << "Проверка работоспособности Cell..." << "\n";
    Cell Cell1;
    UnitTest::AssertEqual(Cell1.getValue(), OPEN);
    Cell1.reValue(CLOSE);
    UnitTest::AssertEqual(Cell1.getValue(), CLOSE);
    Cell Cell2 = Cell1;
    UnitTest::AssertEqual(Cell2.getValue(), CLOSE);
    cout << "Проверка пройдена!" << "\n";

    cout << "Проверка работоспособности Map..." << "\n";
    Map* map1 = Map::getInstance();
    Map* map2 = Map::getInstance();
    try{
        if(map1 != map2){
            throw -1;
        }
    }
    catch(int){
        UnitTest::Assert();
    }
    cout << "Проверка пройдена!" << "\n";
    /*
    cout << "Проверка работоспособности Map_Iterartor..." << "\n";
    Map_Iterator* iter1 = map1->createIterator();
    */
   delete map1;
}