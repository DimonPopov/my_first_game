#include "Behavior.h"
#include <memory>



Neutral::Neutral(){
    iter = std::make_unique<Iterator>(PlayerOrEnemy::IamENEMY);
}

void Neutral::move(unsigned x, unsigned y){
  
}


unsigned Neutral::getX(){
    return iter->m_positionX;
}



unsigned Neutral::getY(){
    return iter->m_positionY;
}