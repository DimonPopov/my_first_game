#include "Enemy1.h"
#include "./Behavior/Behavior.h"


Enemy1::Enemy1():behavior(){
    at = -75;
    behavior = std::make_shared<Aggressive>();
    RedEnemy.loadFromFile("./texture/Red.png");
	RedEnemy.setSmooth(true);
    Red.setTexture(RedEnemy);
    Red.setTextureRect(sf::IntRect(0, 0, 200, 200));
    Red.setScale(0.5f, 0.5f);
    
}


int Enemy1::giveMeAt(){
    return at;
}


void Enemy1::behaviorMove(unsigned x, unsigned y){
    behavior->move(x,y);
}   



void Enemy1::setBehavior(std::shared_ptr<IBehavior> newBehavior){
    behavior = newBehavior;
}



unsigned Enemy1::getPositionX(){
    return behavior->getX();
}



unsigned Enemy1::getPositionY(){
    return behavior->getY();
}