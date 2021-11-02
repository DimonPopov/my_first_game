#include "../Object.h"
#include "Factory1.h"

std::shared_ptr<IElements> Factory1::createElement(){
    return std::make_shared<Obj1>(); 
}