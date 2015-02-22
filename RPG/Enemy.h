#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Entity.h"


class Enemy : public Entity
{
public:
	Enemy(void);
	Enemy::Enemy(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance);
	virtual ~Enemy(void);

	virtual void playing(float  angle);
};


#endif

