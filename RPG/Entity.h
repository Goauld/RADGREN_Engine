#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SFML/Graphics.hpp>
#include "DinamicObject.h"
#include "Input.h"


class Entity : public DinamicObject
{
protected:
	//sf::Vector2f position;
	//sf::Texture texture;
	//sf::Sprite sprite;
	//float velocity;
	float hp,mp,lvl,attack_distance;
	int width_world;
	int height_world;

public:
	Entity(void);
	//Entity(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance);
	virtual ~Entity(void);

	inline sf::Vector2f getPosition()							{	return position;				}
	inline virtual void setPosition(sf::Vector2f & position)	{	this->position = position;		}
	inline sf::Vector2f getXPosition()							{	return xPosition;				}
	inline const float & getVelocity()							{   return velocity;				}
	inline virtual void setVelocity(const float & velocity)		{   this->velocity = velocity;		}
	inline virtual void addVelocity(const float & a)			{   velocity += a;					}
	inline const float & getHp()								{   return hp;						}
	inline virtual void setHp(const float & hp)					{   this->hp = hp;					}
	inline virtual void addHp(const float & hp)					{   this->hp += hp;					}
	inline const float & getMp()								{   return mp;						}
	inline virtual void setMp(const float & mp)					{   this->mp = mp;					}
	inline virtual void addMp(const float & mp)					{   this->mp += mp;					}
	inline const float & getLvl()								{   return lvl;						}
	inline virtual void setLvl(const float & lvl)				{   this->lvl = lvl;				}
	inline virtual void addLvl(const float & lvl)				{   this->lvl += lvl;				}


	virtual void playing(Input & input);
	virtual void update(float & time);
	//virtual void draw(sf::RenderWindow & window);
	virtual void goBack(void);
};


#endif