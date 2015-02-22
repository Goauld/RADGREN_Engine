#include "Player.h"


Player::Player(void)
{
}

	Player::Player(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance)
	{
		this->velocity = velocity;
		this->hp = hp;
		this->mp = mp;
		this->lvl = lvl;
		this->attack_distance = attack_distance;
		this->width_world = width_world;
		this->height_world = height_world;


		texture.loadFromFile("Resources/Textures/pixelone.png"); //!!!
		sprite.setTexture(texture);
	}


Player::~Player(void)
{
}
