#include "../Snowman.h"
#include "SnowmanFactory.h"
#include "IFactory.h"



IElements* SnowmanFactory::createElement(){ 
    return new Snowman; 
    }