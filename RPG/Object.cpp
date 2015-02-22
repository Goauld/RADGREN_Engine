#include "Object.h"


	Object::Object(void)
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Object::Object(sf::Vector2f  position, std::string name)
	{
		this->position = position;
		this->name = name;
		sprite.setPosition(this->position);
	}


	Object::~Object(void)
	{

	}

	const std::string & Object::getName()
	{
		return name;
	}

	void Object::setPosition(sf::Vector2f & position)
	{
		this->position = position;
		//sprite.setTexture(texture);
		sprite.setPosition(position);
	}

	void Object::setTexture(sf::Texture & texture)
	{
		this->texture = texture;
		sprite.setTexture(texture);
	}

	void Object::setTexture(std::string nameFile)
	{
		texture.loadFromFile(nameFile);
		sprite.setTexture(texture);
	}

	const sf::Vector2f & Object::getPosition()
	{
		return position;
	}

	void Object::setWidth(float w)
	{
		width = w;
	}

	void Object::setHeight(float h)
	{
		height = h;
	}

	int Object::getTop()
	{
		return position.y;
	}

	int Object::getLeft()
	{
		return position.x;
	}

	int Object::getRight()
	{
		return position.x + width;
	}

	int Object::getBottom()
	{
		return position.y + height;
	}

	void Object::draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
	}
