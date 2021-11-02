#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "./ClasesForProject/Map.h"   
#include "./ClasesForProject/Player.h"



int main(){
/*
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Works!");
    window.clear(sf::Color(250,220,100,0));
    sf::Event event;

    while (window.pollEvent(event))
    {
        // Пользователь нажал на «крестик» и хочет закрыть окно?
        if (event.type == sf::Event::Closed)
            // Тогда закрываем его
            window.close();
    }
    
    window.display();
*/

    std::unique_ptr<Map> field(Map::getInstance());
    std::unique_ptr<Player> P1(new Player());
    P1->move();
    std::cout << "You win!" << "\n";

    return 0;
}