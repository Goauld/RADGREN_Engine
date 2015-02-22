#ifndef _CORE_ENGINE_H_
#define _CORE_ENGINE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "State.hpp"
#include "Menu.h"
#include "Input.h"
#include <windows.h>


class CoreEngine
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	sf::View view;
	State state;
	Game* game;
	Menu menu;
	Input input;
	const float LIMIT_TIME;
	bool isRunning;
	int width;
	int height;
	float time;

	void run();
	void stop();
	void cleanUp();

public:
	CoreEngine(int width, int height, Game* game);
	~CoreEngine(void);

	void createWindow(std::string name);
	void start();

};


#endif