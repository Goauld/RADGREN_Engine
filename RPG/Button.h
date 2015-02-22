#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SFML/Graphics.hpp>


class Button
{
private:
	sf::Vector2f position;
	float width;
	float height;
	bool pressed;
	sf::Texture textureDown;
	sf::Texture textureUp;
	sf::Sprite sprite;

public:
	Button(sf::Vector2f position, float width, float height);
	Button(float Xpos, float Ypos, float width, float height);
	virtual ~Button(void);

	inline int getWidth()				{ return width;	  }
	inline int getHeight()				{ return height;  }
	void setTextureUp(std::string nameFile, int x, int y);
	void setTextureDown(std::string nameFile, int x, int y);
	void setTextureUp(sf::Texture& texture);
	void setTextureDown(sf::Texture& texture);
	void setTextureUp(sf::Image& image, sf::IntRect& intRect);
	void setTextureDown(sf::Image& image, sf::IntRect& intRect);
	inline void setIsPressed(bool a)	{ pressed = a;	  }
	inline bool isPressed()				{ return pressed; }
	inline sf::Vector2f getPosition()   { return position;}

	bool isCollision(sf::Vector2f pset);
	void draw(sf::RenderWindow& window);


};


#endif