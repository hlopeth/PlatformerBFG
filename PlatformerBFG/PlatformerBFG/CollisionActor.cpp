#include "CollisionActor.h"

bool Collidable::colliding(const RectangleShape& collisionBox1, const RectangleShape& collisionBox2) {
	bool collideX =
		(collisionBox1.getPosition().x + collisionBox1.getSize().x > collisionBox2.getPosition().x) &&
		(collisionBox1.getPosition().x <= collisionBox2.getPosition().x) ||
		(collisionBox2.getPosition().x + collisionBox2.getSize().x > collisionBox1.getPosition().x) &&
		(collisionBox2.getPosition().x <= collisionBox1.getPosition().x);
	bool collideY =
		(collisionBox1.getPosition().y + collisionBox1.getSize().y > collisionBox2.getPosition().y) &&
		(collisionBox1.getPosition().y <= collisionBox2.getPosition().y) ||
		(collisionBox2.getPosition().y + collisionBox2.getSize().y > collisionBox1.getPosition().y) &&
		(collisionBox2.getPosition().y <= collisionBox1.getPosition().y);
	return collideX && collideY;
}

Vector2f Collidable::getCollideMove(const RectangleShape& cb1, const RectangleShape& cb2) {
	float moveX = min(
		abs(cb1.getPosition().x + cb1.getSize().x - cb2.getPosition().x),
		abs(cb1.getPosition().x - cb2.getPosition().x - cb2.getSize().x)
	);
	if (cb1.getPosition().x < cb2.getPosition().x)
		moveX = -moveX;
	float moveY = min(
		abs(cb1.getPosition().y + cb1.getSize().y - cb2.getPosition().y),
		abs(cb1.getPosition().y - cb2.getPosition().y - cb2.getSize().y)
	);
	if (cb1.getPosition().y < cb2.getPosition().y)
		moveY = -moveY;
	if (abs(moveX) < abs(moveY))
		return Vector2f(moveX, 0);
	else
		return Vector2f(0, moveY);
}