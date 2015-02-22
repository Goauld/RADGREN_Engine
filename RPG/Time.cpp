#include "Time.h"


	Time::Time(void):SECOND(1000000000)
	{
		clock1.restart();
		clock2.restart();
	}


	Time::~Time(void)
	{
		
	}


	float Time::getTime()
	{
		return (float)clock1.getElapsedTime().asMicroseconds();
	}

	float Time::getSmallTime()
	{
		clock2.restart();
		return (float)clock2.getElapsedTime().asMicroseconds();
	}