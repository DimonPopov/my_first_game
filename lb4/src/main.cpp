#include <memory>
#include "./Map/Game.h"


int main(){

	std::unique_ptr<Game> myGame(new Game);
	myGame->menuWindow();
	

	return 0;
}