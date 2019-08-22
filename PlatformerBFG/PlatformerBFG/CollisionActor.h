#pragma once
#include <cmath>
#include "Actor.h"

using std::min;

class Collidable {
public:
	virtual RectangleShape getCollisionBox() = 0;
	virtual void onCollide(RectangleShape collisionBox) = 0;
	static bool colliding(const RectangleShape &collisionBox1,const RectangleShape &collisionBox2);
	//как должен сдваинуться collidionBox1 что бы не пересикаться с collisionBox2
	Vector2f getCollideMove(const RectangleShape& collisionBox1, const RectangleShape& collisionBox2);
};