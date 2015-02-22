#include "Enemy.h"


	Enemy::Enemy(void)
	{
	}


	
	Enemy::Enemy(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance)
	{
		this->velocity = velocity;
		this->hp = hp;
		this->mp = mp;
		this->lvl = lvl;
		this->attack_distance = attack_distance;
		this->width_world = width_world;
		this->height_world = height_world;


		texture.loadFromFile("Resources/Textures/enemy.png"); //!!!
		sprite.setTexture(texture);
	}


	Enemy::~Enemy(void)
	{
	}


	void Enemy::playing(float  angle)
	{
		xPosition = position;
		position.x += cos(angle / 57.3f) * velocity;
		position.y -= sin(angle / 57.3f) * velocity;
	}