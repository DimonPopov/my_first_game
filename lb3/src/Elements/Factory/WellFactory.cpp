#include "../Well.h"
#include "WellFactory.h"
#include "IFactory.h"



IElements* WellFactory::createElement(){ 
    return new Well; 
    }