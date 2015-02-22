#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "Entity.h"


class PhysicsSystem
{
public:

	PhysicsSystem()
	{
	
	}

	bool getCollision(Object * obj1, Object * obj2)
	{
		float l1 = obj1->getLeft();
		float t1 = obj1->getTop();
		float r1 = obj1->getRight();
		float b1 = obj1->getBottom();

		float l2 = obj2->getLeft();
		float t2 = obj2->getTop();
		float r2 = obj2->getRight();
		float b2 = obj2->getBottom();

		if(b1 < t2 || t1 > b2 || r1 < l2 || l1 > r2)
			return false;

		return true;
	}


	float getAngle(sf::Vector2f  a, sf::Vector2f  b, sf::Vector2f  c)
	{
		float x1 = a.x - b.x, x2 = c.x - b.x;
		float y1 = a.y - b.y, y2 = c.y - b.y;
		float d1 = sqrt(x1 * x1 + y1 * y1);
		float d2 = sqrt(x2 * x2 + y2 * y2);

		if (b.y > a.y) 
			return (acos((x1 * x2 + y1 * y2) / (d1 * d2))) * 57.3f;
		else 
			return 360 - (acos((x1 * x2 + y1 * y2) / (d1 * d2))) * 57.3f;
	}

	float getLenght(sf::Vector2f & a, sf::Vector2f & b)
	{
		return (sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y))) * 57.3f;
	}

};

	/*bool getCollisionPset(Object * ent, sf::Vector2f & pset)
	{
		if(pset.x > ent->getLeft() && pset.x > ent->getRight() && pset.y > ent->getTop() && pset.y < ent->getBottom())
			return true;

		return false;
	}*/

	/*void collisionResult(Entity * ent1)
	{
		ent1->goBack();
	}*/



#endif