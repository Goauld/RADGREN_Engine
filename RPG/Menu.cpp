#include "Menu.h"


	Menu::Menu(void)
	{
		init = false;
		texture.loadFromFile("Resources/Textures/sprite.bmp");
		sprite.setTexture(texture);
		sprite.setPosition(0.0f,-0.01f);
	}


	Menu::~Menu(void)
	{

	}



	void Menu::Init(State st)
	{
		switch(st)
		{
			case MAIN_MENU:
				bm.addButton("new game",280,270*1.6,211,46);
				bm.addButton("exit",280,75*1.6,211,46);
				bm.addTextures("Resources/Textures/ConfigTexture.txt", "Resources/Textures/Textures.bmp");
			break;

			case MENU:
				bm.addButton("return to game",280,220*1.6,211,46);
				bm.addButton("exit",280,100*1.6,211,46);
				bm.addTextures("Resources/Textures/ConfigTexture2.txt", "Resources/Textures/Textures2.bmp");
			break;

		}
	}
	
	State Menu::firstUpdate(sf::RenderWindow& window, Input& input)
	{
		if(!init)
		{
			Init(MAIN_MENU);
			init = true;
		}


		bm.setPressed("new game",false);
		bm.setPressed("exit",false);

		if(bm.isPressed("exit", input.GetMousePosition(window)))
			{
				bm.setPressed("exit",true);
			
				if(input.GetMouse(sf::Mouse::Left))
				{
					bm.clear();
					init = false;
					return START;
				}
			}

			if(bm.isPressed("new game", input.GetMousePosition(window)))
			{
				bm.setPressed("new game", true);

				if(input.GetMouse(sf::Mouse::Left))
				{
					bm.clear();
					init = false;
					return CLOSE;
				}
			}

		window.draw(sprite);
		bm.draw(window);
	}
	
	State Menu::mainUpdate(sf::RenderWindow& window, Input& input)
	{
		if(!init)
		{
			Init(MENU);
			init = true;
		}


		bm.setPressed("return to game", false);
		bm.setPressed("exit", false);


			if(bm.isPressed("return to game", input.GetMousePosition(window)))
			{
				bm.setPressed("return to game",true);

				if(input.GetMouse(sf::Mouse::Left))
				{
					bm.clear();
					init = false;
					return SAVE;
				}
			}

			if(bm.isPressed("exit", input.GetMousePosition(window)))
			{
				bm.setPressed("exit", true);

				if(input.GetMouse(sf::Mouse::Left))
				{
					bm.clear();
					init = false;
					return GAME;
				}
			}

		window.draw(sprite);
		bm.draw(window);

		return MENU;
	}

	State Menu::gameUpdate(sf::RenderWindow& window, Input& input)
	{
		/*
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			return MENU;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			return CLOSE;
		else
			return GAME;*/

		if(input.GetKey(sf::Keyboard::Escape))
			return MENU;
		else if(input.GetKey(sf::Keyboard::P))
			return CLOSE;
		else
			return GAME;
	}


	State Menu::psuseUpdate(sf::RenderWindow& window,Input& input)
	{
		return GAME;
	}
