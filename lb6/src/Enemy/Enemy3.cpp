#include "Enemy3.h"
#include "./Behavior/Behavior.h"



Enemy3::Enemy3(){
    at = -4;
    behavior = std::make_shared<Passive>();
    PurpleEnemy.loadFromFile("./texture/Purple.png");
	PurpleEnemy.setSmooth(true);
    Purple.setTexture(PurpleEnemy);
    Purple.setTextureRect(sf::IntRect(0, 0, 200, 200));
	Purple.setScale(0.5f, 0.5f);
}


int Enemy3::giveMeAt(){
    return at;
}



void Enemy3::behaviorMove(unsigned x, unsigned y){
    behavior->move(x,y);
}   



void Enemy3::setBehavior(std::shared_ptr<IBehavior> newBehavior){
    behavior = newBehavior;
}



unsigned Enemy3::getPositionX(){
    return behavior->getX();
}



unsigned Enemy3::getPositionY(){
    return behavior->getY();
}