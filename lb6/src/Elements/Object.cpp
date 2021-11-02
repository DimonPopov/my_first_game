#include <iostream>

#include "../Enum/CellAndElemENUM.h"
#include "Object.h"



Obj1::Obj1(){
    WhoAmI = CellTypes::OBJ1;
    myName = "coint";
    coint = 1;
    countOfUses = 1;
}

int Obj1::WhatAreYou(){ return WhoAmI; }

std::string Obj1::whatName(){ return myName; }

int Obj1::giveMeCoints(){ return coint; }

std::ostream& operator<< (std::ostream &out, const Obj1 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}

std::ofstream& operator<< (std::ofstream &out, const Obj1 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}

//======================================================================================================================================

Obj2::Obj2():WhoAmI(CellTypes::OBJ2), myName("obj2"), coint(10){}

int Obj2::WhatAreYou(){ return WhoAmI; }

std::string Obj2::whatName(){ return myName; }

int Obj2::giveMeCoints(){ return coint; }

std::ostream& operator<< (std::ostream &out, const Obj2 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}

std::ofstream& operator<< (std::ofstream &out, const Obj2 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}


//======================================================================================================================================


Obj3::Obj3():WhoAmI(CellTypes::OBJ3), myName("obj3"), coint(0){}

int Obj3::WhatAreYou(){ return WhoAmI; }

std::string Obj3::whatName(){ return myName; }

int Obj3::giveMeCoints(){ return coint; }

std::ostream& operator<< (std::ostream &out, const Obj3 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}

std::ofstream& operator<< (std::ofstream &out, const Obj3 &obj){
    out << "Объект " << obj.myName << " имеет " << obj.coint << ", кол-во возможных взаимодействий - " << obj.countOfUses << '\n';
    return out;
}