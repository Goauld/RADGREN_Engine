#include <conio.h>
#include <SFML\Window\Mouse.hpp>
#include "TestGame.h"
#include "Game.hpp"
#include "CoreEngine.h"
#include "Button.h"
#include "ButtonManager.h"
#include "Menu.h"
#include "Input.h"


int main()
{
	int w = 775;
	int h = 575;

	Game* game = nullptr;
	game = new TestGame;
	if(game == nullptr)
		return 1;

	CoreEngine core(w,h,game);
	core.createWindow("RADGREN");
	core.start();


	if(game != nullptr)
		delete game;

return 0;
}