#include "DataPanel.h"


	DataPanel::DataPanel(sf::Vector2f position, sf::Vector2f posLvl, sf::Vector2f posHp, sf::Vector2f posMp)
	{
	this->position = position;
	this->posLvl = posLvl;
	this->posHp = posHp;
	this->posMp = posMp;
	limPoint = 0;
//	sprite.setPosition(position);
	}


	DataPanel::~DataPanel(void)
	{
	}
	
	
	void DataPanel::setTexrures(std::string name1, std::string name2)
	{
	texture.loadFromFile(name1);
	sprite.setTexture(texture);
	texturePoint.loadFromFile(name2);
	spritePoint.setTexture(texturePoint);
	}
	
	void DataPanel::draw(sf::RenderWindow& window, int lvl, int hp, int mp)
	{
		window.draw(sprite);
		
		int i;
		
		for(i = 0; i < lvl; i++)
		{
			if(i >= limPoint) break;

			spritePoint.setPosition(position.x+posLvl.x+lenghtPoint*i, position.y+posLvl.y);
			window.draw(spritePoint);
		}
		
		for(i = 0; i < hp; i++)
		{
			if(i >= limPoint) break;

			spritePoint.setPosition(position.x+posHp.x+lenghtPoint*i, position.y+posHp.y);
			window.draw(spritePoint);
		}
		
		for(i = 0; i < mp; i++)
		{
			if(i >= limPoint) break;

			spritePoint.setPosition(position.x+posMp.x+lenghtPoint*i, position.y+posMp.y);
			window.draw(spritePoint);
		}
	}