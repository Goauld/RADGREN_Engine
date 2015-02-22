#ifndef _TIME_H_
#define _TIME_H_

#include <SFML/Graphics.hpp>


class Time
{
private:
	sf::Clock clock1;
	sf::Clock clock2;

public:
	const float SECOND;

	Time(void);
	~Time(void);

	float getTime();
	float getSmallTime();

};


#endif