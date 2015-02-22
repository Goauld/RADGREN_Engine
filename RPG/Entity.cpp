#include "Entity.h"


	Entity::Entity(void)
	{
		velocity = 0.0f;
		hp = mp = lvl = attack_distance = 0.0f;
		width_world = 0.0f;
		height_world = 0.0f;
	}

	/*Entity::Entity(int width_world, int height_world, float velocity, float hp, float mp, float lvl, float attack_distance)
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
	}*/

	Entity::~Entity(void)
	{
	}


	void Entity::playing(Input & input)
	{
		xPosition = position;

		if(input.GetKey(sf::Keyboard::D))
			position.x += velocity;
		if(input.GetKey(sf::Keyboard::A))
			position.x -= velocity;
		if(input.GetKey(sf::Keyboard::W))
			position.y -= velocity;
		if(input.GetKey(sf::Keyboard::S))
			position.y += velocity;

		if(position.x < -128.0f)
			position.x = -128.0f;
		if(position.x > width_world-32-128) // !!!  32 - width player, 128 - width right panel
			position.x = width_world-32-128;

		if(position.y < 0.0f)
			position.y = 0.0f;
		if(position.y > height_world-32) // !!!	32 - height player
			position.y = height_world-32;
	}

	void Entity::update(float & time)
	{
		sprite.setPosition(position);
	}

	/*void Entity::draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
	}*/

	void Entity::goBack(void)
	{
		position = xPosition;
	}