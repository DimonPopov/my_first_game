#include "Behavior.h"
#include <memory>
#include <time.h>


Passive::Passive(){
    iter = std::make_unique<Iterator>(PlayerOrEnemy::IamENEMY);
}

void Passive::move(unsigned x, unsigned y){
    srand(time(nullptr));
    int variant = rand() % 4;
    if(variant == 0){
        iter->down();
    }else if(variant == 1){
        iter->up();
    }else if(variant == 2){
        iter->left();
    }else if(variant == 3){
        iter->right();
    }
}


unsigned Passive::getX(){
    return iter->m_positionX;
}



unsigned Passive::getY(){
    return iter->m_positionY;
}