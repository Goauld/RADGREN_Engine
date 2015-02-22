#ifndef _DINAMIC_OBJECT_H_
#define _DINAMIC_OBJECT_H_

#include "Object.h"


class DinamicObject : public Object
{
protected:
	float velocity;
	sf::Vector2f xPosition;

public:
	DinamicObject(void);
	DinamicObject(sf::Vector2f & position, std::string name);
	virtual ~DinamicObject(void);

	const std::string & getName();
	virtual void setPosition(sf::Vector2f & position);
	virtual void setTexture(sf::Texture & texture);
	virtual void setTexture(std::string nameFile);

	virtual void setVelocity(float velocity);
	virtual void addVelocity(float acceleration);
	virtual const float & getVelocity();
	virtual void update(const float & time);

	//virtual void draw(sf::RenderWindow & window);
};


#endif