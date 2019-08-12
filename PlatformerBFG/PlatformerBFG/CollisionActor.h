#pragma once
#include "Actor.h"

class CollisionActor {
	virtual RectangleShape getCollisionBox() = 0;
};