#include "Enemy2.h"
#include "./Behavior/Behavior.h"



Enemy2::Enemy2(){
    at = -5;
    behavior = std::make_shared<Neutral>();
    GreenEnemy.loadFromFile("./texture/Green.png");
	GreenEnemy.setSmooth(true);
    Green.setTexture(GreenEnemy);
    Green.setTextureRect(sf::IntRect(0, 0, 200, 200));
	Green.setScale(0.5f, 0.5f);
}


int Enemy2::giveMeAt(){
    return at;
}



void Enemy2::behaviorMove(unsigned x, unsigned y){
    behavior->move(x,y);
}   



void Enemy2::setBehavior(std::shared_ptr<IBehavior> newBehavior){
    behavior = newBehavior;
}



unsigned Enemy2::getPositionX(){
    return behavior->getX();
}



unsigned Enemy2::getPositionY(){
    return behavior->getY();
}