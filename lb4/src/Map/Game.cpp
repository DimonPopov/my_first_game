#include "Game.h"
#include "../Enum/CellAndElemENUM.h"
#include <sstream>

#include <vector>



void Game::menuWindow(){

    window.create(sf::VideoMode(7 * 100, 7 * 100), "myGame"); // !!!!!!

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

    map = Map::getInstance();
	player = std::make_unique<Player>();

	if(!window.isOpen()){
    	window.create(sf::VideoMode(map->getHeight() * 100, map->getWidth() * 100), "myGame");
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

	//window.clear(sf::Color(251, 230, 208, 0));

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
			}
		}
		window.clear(sf::Color(251, 230, 208, 0));

		int CellValue;
		for(size_t i = 0; i < map->getWidth(); i++){
			for(size_t j = 0; j < map->getHeight(); j++){

				CellValue = map->getCellValue(i, j);

				if(i == player->myPositionX() && j == player->myPositionY()){
					Rico.setPosition(i * 100, j * 100);
					if(CellValue == CellTypes::EXIT && player->getCoins() >= 10){
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
				window.draw(Rico);
				window.draw(text);
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