#ifndef _TEST_GAME_H_
#define _TEST_GAME_H_

#include "Game.hpp"


class TestGame : public Game
{
private:

public:
	TestGame(void);
	~TestGame(void);

	virtual void init(const int & w, const int & h, sf::RenderWindow * window);
	virtual void input(Input& input);
	virtual void start();
	virtual void update(const float& time);
	virtual void save();
	virtual void loading(Input& input);
	virtual void render();
	virtual bool isLoad();
	virtual void close();

};


#endif