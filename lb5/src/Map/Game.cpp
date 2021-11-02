#include "Game.h"
#include "../Enum/CellAndElemENUM.h"
#include "../Enemy/Enemy1.h"
#include "../Enemy/Enemy2.h"
#include "../Enemy/Enemy3.h"

#include <sstream>
#include <vector>



void Game::menuWindow(){

	setting = std::make_shared<GameSetting>();

    window.create(sf::VideoMode(setting->width * setting->sizeSquare, setting->height * setting->sizeSquare), "myGame");

    sf::Font font;
    font.loadFromFile("./Map/2.ttf");

    std::vector<sf::Text> arrString{};

    sf::Text newGame("New game", font, 30);
    sf::Text loadGame("Load game", font, 30);
    sf::Text endGame("Exit", font, 30);
	sf::Text caret("<", font, 30);

	arrString.emplace_back(newGame);
    arrString.emplace_back(loadGame);
    arrString.emplace_back(endGame);

	unsigned width = 100;	// Расстояние по горизонтали 
	unsigned height = 100;	// Расстояние по вертикали
	unsigned interval = 50;	// Интервал между надписями

	for(size_t i = 0; i < arrString.size(); i++){
		arrString[i].setPosition(width, height + interval * i);
		arrString[i].setFillColor(sf::Color::Black);
	}

	caret.setPosition(3 * width, height);
	caret.setFillColor(sf::Color::Black);

    size_t iter = 0;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
				this->endGame();
            }

            if (event.type == sf::Event::KeyPressed){

				if(event.key.code == sf::Keyboard::S){
					if(iter < arrString.size() - 1){
						iter++;
						caret.setPosition(300, height + (iter * interval));
					}
				}else if(event.key.code == sf::Keyboard::W){
					if(iter > 0){
						iter--;
						caret.setPosition(300, height + (iter * interval));
					}
				}else if(event.key.code == sf::Keyboard::Up){
					if(iter > 0){
						iter--;
						caret.setPosition(300, height + (iter * interval));
					}
				}else if(event.key.code == sf::Keyboard::Down){
					if(iter < arrString.size() - 1){
						iter++;
						caret.setPosition(300, height + (iter * interval));
					}
				}else if(event.key.code == sf::Keyboard::Return){
					if(iter == 0){ this->newGame(); }
					//if(iter == 1){ this->loadGame(); }
					if(iter == 2){ this->endGame(); }

				}
			}

        }

        window.clear(sf::Color(251, 230, 208, 0));

        for(size_t i = 0; i < arrString.size(); i++){
            window.draw(arrString[i]);
        }
		window.draw(caret);

        window.display();

    }
}





void Game::newGame(){

    map = Map::getInstance(setting->height, setting->width);
	player = std::make_unique<Player>();

	auto enemy1 = std::make_shared<Enemy1>();
	auto enemy2 = std::make_shared<Enemy2>();
	auto enemy3 = std::make_shared<Enemy3>();

	if(!window.isOpen()){
    	window.create(sf::VideoMode(map->getHeight() * setting->sizeSquare, map->getWidth() * setting->sizeSquare), "myGame");
	}

	// Текст кол-ва монеток
	std::ostringstream coinsString;
	coinsString << "Coins: " << player->getCoins();
	sf::Font font;
	font.loadFromFile("./Map/1.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(0, 0);
	text.setString(coinsString.str());

	std::ostringstream HpString;
	HpString << "HP: " << player->getHP();
	sf::Text text2("", font, 20);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(0, 20);
	text2.setString(HpString.str());

	// Спрайт монеток
	sf::Texture coinTexture;
	coinTexture.loadFromFile("./texture/coin.png");
	coinTexture.setSmooth(true);
	sf::Sprite coin(coinTexture);
	coin.setTextureRect(sf::IntRect(0, 0, 100, 100));

	// Спрайт Рикардыча
	sf::Texture playerRicardo;
	playerRicardo.loadFromFile("./texture/Рикардо.png");
	playerRicardo.setSmooth(true);
	sf::Sprite Rico(playerRicardo);
	Rico.setTextureRect(sf::IntRect(0, 0, 100, 100));

	unsigned sideOfAsquare = 100.f;		// Сторона квадрата

	std::vector<sf::RectangleShape> colorRectangle{};
	colorRectangle.resize(CellTypes::MAX);

	sf::RectangleShape rectangleStart(sf::Vector2f(sideOfAsquare, sideOfAsquare));	// Квадрат старта
	sf::RectangleShape rectangleExit(sf::Vector2f(sideOfAsquare, sideOfAsquare));	// Квадрат выхода
	sf::RectangleShape rectangleOpen(sf::Vector2f(sideOfAsquare, sideOfAsquare));	// Квадрат открытой
	sf::RectangleShape rectangleClose(sf::Vector2f(sideOfAsquare, sideOfAsquare));	// Квадрат закрытой

	rectangleStart.setFillColor(sf::Color::Green);
	rectangleExit.setFillColor(sf::Color::Blue);
	rectangleOpen.setFillColor(sf::Color(251, 230, 208, 0));
	rectangleClose.setFillColor(sf::Color::Black);

	colorRectangle[CellTypes::OPEN] = rectangleOpen;
	colorRectangle[CellTypes::CLOSE] = rectangleClose;
	colorRectangle[CellTypes::START] = rectangleStart;
	colorRectangle[CellTypes::EXIT] = rectangleExit;

	unsigned count = 0;

    while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				window.close();
            }
			if (event.type == sf::Event::KeyPressed){

				if(event.key.code == sf::Keyboard::S){
					this->playerMove("down");
				}else if(event.key.code == sf::Keyboard::W){
					this->playerMove("up");
				}else if(event.key.code == sf::Keyboard::A){
					this->playerMove("left");
				}else if(event.key.code == sf::Keyboard::D){
					this->playerMove("right");
				}else if(event.key.code == sf::Keyboard::E){
					player->use();
					coinsString.str("") ;
					coinsString << "Coins: " << player->getCoins();
					text.setString(coinsString.str());
				}
				count++;
				if(count == 3){
					if(enemy1){
						enemy1->behaviorMove(player->myPositionX(), player->myPositionY());
						std::cout << "Ходит enemy1\n";
						if(enemy1->getPositionX() == player->myPositionX() && enemy1->getPositionY() == player->myPositionY()){
							player->use(enemy1);
						}
					}
					if(enemy2){
						enemy2->behaviorMove(player->myPositionX(), player->myPositionY());
						std::cout << "Ходит enemy2\n";
						if(enemy2->getPositionX() == player->myPositionX() && enemy2->getPositionY() == player->myPositionY()){
							player->use(enemy2);
						}
					}
					if(enemy3){
						enemy3->behaviorMove(player->myPositionX(), player->myPositionY());
						std::cout << "Ходит enemy3\n";
						if(enemy3->getPositionX() == player->myPositionX() && enemy3->getPositionY() == player->myPositionY()){
							player->use(enemy3);
						}
					}
					count = 0;
					HpString.str("") ;
					HpString << "HP: " << player->getHP();
					text2.setString(HpString.str());
				}
			}
			if(player->getHP() <= 0){
				text.setString("You lose!");
						text.setFillColor(sf::Color::Red);
						text.setCharacterSize(50);
						text.setPosition(100, 350);
						this->endGame();
			}
		}
		window.clear(sf::Color(251, 230, 208, 0));

		int CellValue;
		for(size_t i = 0; i < map->getWidth(); i++){
			for(size_t j = 0; j < map->getHeight(); j++){

				CellValue = map->getCellValue(i, j);

				if(i == player->myPositionX() && j == player->myPositionY()){
					Rico.setPosition(i * 100, j * 100);
					if(CellValue == CellTypes::EXIT && player->getCoins() >= 15){
						text.setString("You're a winner!");
						text.setFillColor(sf::Color::Red);
						text.setCharacterSize(50);
						text.setPosition(100, 350);
						this->endGame();
					}
				}

				colorRectangle[CellValue].setPosition(i * sideOfAsquare, j * sideOfAsquare);
				window.draw(colorRectangle[CellValue]);
				if(CellValue == CellTypes::OBJ1){
					coin.setPosition(i * 100, j * 100);
					window.draw(coin);
				}
				if(enemy1){
					if(i == enemy1->getPositionX() && j == enemy1->getPositionY()){
						enemy1->Red.setPosition(i * 100, j * 100);
						window.draw(enemy1->Red);
					}
				}
				if(enemy2){
					if(i == enemy2->getPositionX() && j == enemy2->getPositionY()){
						enemy2->Green.setPosition(i * 100, j * 100);
						window.draw(enemy2->Green);
					}
				}
				if(enemy3){
					if(i == enemy3->getPositionX() && j == enemy3->getPositionY()){
						enemy3->Purple.setPosition(i * 100, j * 100);
						window.draw(enemy3->Purple);
					}
				}

				window.draw(Rico);
				window.draw(text);
				window.draw(text2);
			}
		}

        window.display();
	}
}



void Game::endGame(){
	if(window.isOpen()){
		window.close();
	}
}



void Game::playerMove(std::string route){
	if(player){
		player->move(route);
	}
}