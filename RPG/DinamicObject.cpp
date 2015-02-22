#include "DinamicObject.h"


	DinamicObject::DinamicObject(void)
	{
	}


	DinamicObject::DinamicObject(sf::Vector2f & position, std::string name)
	{
		this->position = position;
		this->name = name;
	}


	DinamicObject::~DinamicObject(void)
	{

	}

	const std::string & DinamicObject::getName()
	{
		return name;
	}

	void DinamicObject::setPosition(sf::Vector2f & position)
	{
		this->position = position;
		sprite.setTexture(texture);
	}

	void DinamicObject::setTexture(sf::Texture & texture)
	{
		this->texture = texture;
		sprite.setTexture(texture);
	}

	void DinamicObject::setTexture(std::string nameFile)
	{
		texture.loadFromFile(nameFile);
		sprite.setTexture(texture);
	}

	void DinamicObject::setVelocity(float velocity)
	{
		this->velocity = velocity;
	}

	void DinamicObject::addVelocity(float acceleration)
	{
		velocity += acceleration;
	}

	const float & DinamicObject::getVelocity()
	{
		return velocity;
	}

	void DinamicObject::update(const float & time)
	{
		
	}

	/*void DinamicObject::draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
	}*/

