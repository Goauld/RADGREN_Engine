#ifndef _BULLET_H_
#define _BULLET_H_

#include "DinamicObject.h"


class Bullet : public DinamicObject
{
private:
	float liveTime, damage, angle;
	sf::Vector2f pointPos;

public:
	Bullet(sf::Vector2f & position, float liveTime, sf::Texture & texture, float w, float h, float damage, float angle);
	virtual ~Bullet(void);

	virtual void update(float & time);

	inline const float & getLiveTime()	 { return liveTime;	}
};


#endif