#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "Input.h"

//#include "Entity.h"


class Game
{
protected:
	bool load;
	sf::RenderWindow * window;

public:
	virtual void init(const int& w, const int& h, sf::RenderWindow * window) = 0;
	virtual bool isLoad() = 0;
	virtual void input(Input& input) = 0;
	virtual void start() = 0;
	virtual void update(const float& time) = 0;
	virtual void save() = 0;
	virtual void loading(Input& input) = 0;
	virtual void render() = 0;
	virtual void close() = 0;

};


#endif
