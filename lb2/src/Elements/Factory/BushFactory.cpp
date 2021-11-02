#include "../IElements.h"
#include "../Bush.h"
#include "BushFactory.h"

IElements* BushFactory::createElement(){ 
    return new Bush; 
    }