#include "Bullet.h"


	Bullet::Bullet(sf::Vector2f & position, float liveTime, sf::Texture & texture, float w, float h, float damage, float angle)
	{
		this->position = position;
		this->pointPos = pointPos;
		this->liveTime = liveTime;
		this->texture = texture;
		//texture.loadFromFile("Resources/Textures/bullet.png");
		sprite.setTexture(texture);
		sprite.setRotation(angle);
		this->width = w;
		this->height = h;
		this->damage = damage;
		this->angle = angle;
		velocity = 11.0f;
	}


	Bullet::~Bullet(void)
	{
	}


	void Bullet::update(float & time)
	{
		xPosition = position;
		liveTime -= 1.0f;
		//position += pointPos * velocity;
		position.x += cos(angle / 57.32484076433121f) * velocity;
		position.y += sin(angle / 57.32484076433121f) * velocity;
		//position.x += velocity;
		sprite.setPosition(position);
	}