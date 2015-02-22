#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"


class Player : public Entity
{
public:
	Player(void);
	Player(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance);
	virtual ~Player(void);
};


#endif
