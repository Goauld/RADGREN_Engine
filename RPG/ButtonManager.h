#ifndef _BUTTONMANAGER_H_
#define _BUTTONMANAGER_H_

#include <fstream>
#include "Button.h"
#include "Input.h"

class ButtonManager
{
private:
	int numberButton;
	std::map<std::string, Button> ListButton;
	std::map<std::string, Button>::iterator it;
	Button* button;
	std::ifstream fin;

public:
	ButtonManager(void);

	virtual ~ButtonManager(void);

	inline void setNumberButton(int numberButton)	{ this->numberButton = numberButton; }

	inline int getNumberButton()					{ return numberButton;				 }

	void addButton(std::string name, const sf::Vector2f& position, const float& width, const float& height);

	void addButton(std::string name, float Xpos, float Ypos, const float& width, const float& height);

	void setTetureButton(std::string nameButton, sf::Texture& textureUp, sf::Texture& textureDown);

	void setPressed(std::string nameButton, bool a);

	/* в nameConfigFile (текстовый документ) должны содержаться координаты текстуры из nameTextureFile (картинка) 
	каждой кнопки (как вкл. так выкл. состояния - по очереди для каждой) */
	void addTextures(std::string nameConfigFile, std::string nameTextureFile); 

	bool isPressed(std::string nameButton, sf::Vector2f mousePosition);

	void draw(sf::RenderWindow& window);

	void clear();

};


#endif
