#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/Graphics.hpp>


class Object
{
protected:
	sf::Vector2f position;
	int width, height;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string name;
	bool isDead;

public:
	Object(void);
	Object(sf::Vector2f  position, std::string name);
	virtual ~Object(void);

	const std::string & getName();
	virtual void setPosition(sf::Vector2f & position);
	virtual void setTexture(sf::Texture & texture);
	virtual void setTexture(std::string nameFile);
	const sf::Vector2f & getPosition();
	void setWidth(float w);
	void setHeight(float h);
	int getTop();
	int getLeft();
	int getRight();
	int getBottom();
	inline void setIdDead(bool a)	{ isDead = a;    }
	inline bool getIdDead()			{ return isDead; }

	virtual void draw(sf::RenderWindow & window);
};


#endif
