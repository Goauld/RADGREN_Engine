#ifndef _MENU_H_
#define _MENU_H_

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "ButtonManager.h"
#include "Input.h"


class Menu
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float w;
	float h;
	ButtonManager bm;
	bool init;

	void Init(State st);

public:
	Menu(void);
	~Menu(void);

	State firstUpdate(sf::RenderWindow& window, Input& input);
	State mainUpdate(sf::RenderWindow& window, Input& input);
	State gameUpdate(sf::RenderWindow& window, Input& input);
	State psuseUpdate(sf::RenderWindow& window,Input& input);

};


#endif
