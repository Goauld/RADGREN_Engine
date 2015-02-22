#ifndef _DATA_PANEL_H_
#define _DATA_PANEL_H_

#include "Object.h"
//#include <SFML\Graphics.hpp>


class DataPanel : public Object
{
private:
sf::Vector2f posLvl, posHp, posMp;
sf::Texture texturePoint;
sf::Sprite spritePoint;
float lenghtPoint, limPoint;

public:
	DataPanel(sf::Vector2f position, sf::Vector2f posLvl, sf::Vector2f posHp, sf::Vector2f posMp);
	~DataPanel(void);

	inline void	 setLenght(float a)		{    lenghtPoint = a;		}
	inline const float & getLenght()	{    return lenghtPoint;	}
	inline void	 setLimPoint(float a)	{    limPoint = a;			}
	inline const float & getLimPoint()	{    return limPoint;		}


	virtual void draw(sf::RenderWindow& window, int lvl, int hp, int mp);
	virtual void setTexrures(std::string name1, std::string name2);
};


#endif

