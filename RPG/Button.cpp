#include "Button.h"


	Button::Button(sf::Vector2f position, float width, float height)
	{
		this->position = position;
		this->width = width;
		this->height = height;
		pressed = false;
		sprite.setPosition(position);
	}

	Button::Button(float Xpos, float Ypos, float width, float height)
	{
		this->position.x = Xpos;
		this->position.y = Ypos;
		this->width = width;
		this->height = height;
		pressed = false;
		sprite.setPosition(position);
	}

	Button::~Button(void)
	{

	}

	void Button::setTextureUp(std::string nameFile, int x, int y)
	{
		sf::IntRect intRect;
		intRect.height = (int)height;
		intRect.left = x;
		intRect.width = (int)width;
		intRect.top = y;
		sf::Image image;
		image.loadFromFile(nameFile);
		textureUp.loadFromImage(image, intRect);
		//sprite.setTexture(textureUp);
	}

	void Button::setTextureDown(std::string nameFile, int x, int y)
	{
		sf::IntRect intRect;
		intRect.height = (int)height;
		intRect.left = x;
		intRect.width = (int)width;
		intRect.top = y;
		sf::Image image;
		image.loadFromFile(nameFile);
		textureDown.loadFromImage(image, intRect);
		//sprite.setTexture(textureDown);
	}

	void Button::setTextureUp(sf::Texture& texture)
	{
		textureUp = texture;
	}

	void Button::setTextureDown(sf::Texture& texture)
	{
		textureDown = texture;
	}
	
	void Button::setTextureUp(sf::Image& image,sf::IntRect& intRect)
	{
		textureUp.loadFromImage(image, intRect);
	}

	void Button::setTextureDown(sf::Image& image,sf::IntRect& intRect)
	{
		textureDown.loadFromImage(image, intRect);
	}

	bool Button::isCollision(sf::Vector2f pset)
	{
		if((pset.x > position.x) && (pset.x < position.x + width) && 
			(pset.y > position.y) && (pset.y < position.y + height))
				return true;

		return false;
	}

	void Button::draw(sf::RenderWindow& window)
	{
		if(pressed)
			sprite.setTexture(textureDown);
		else sprite.setTexture(textureUp);

		window.draw(sprite);
	}
