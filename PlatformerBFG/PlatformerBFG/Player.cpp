#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	rect.setFillColor(Color::Red);
	rect.setSize(Vector2f(25, 50));
	rect.setPosition(Vector2f(0, 0));
}

Player::Player(Vector2f position) : Player() {
	rect.setPosition(position);
}

void Player::update(float time, float deltaTime) {
	PhysicsActor::update(time, deltaTime);

	float timeInSeconds = deltaTime * 0.001;
	Vector2f delta = speed * (timeInSeconds * PIXEL_IN_METER);
	rect.move(delta);
}

void Player::draw(RenderWindow& window) {
	window.draw(rect);
	screenSize = window.getSize();
	inAir = true;
	onWallLeft = false;
	onWallRight = false;
}

RectangleShape Player::getCollisionBox() {
	return rect;
}

void Player::onCollide(RectangleShape collisionBox) {
	Vector2f collideMove = Collidable::getCollideMove(getCollisionBox(), collisionBox);
	if (collideMove.y < 0) {
		accseleration.y = 0;
		inAir = false;
	}
	if (collideMove.x > 0) {
		onWallLeft = true;
	}
	if (collideMove.x < 0) {
		onWallRight = true;
	}
	rect.move(collideMove);
}

void Player::keyEvent(Event event) {
	auto key = event.key.code;
	if (event.type == Event::KeyPressed) {
		switch (key)
		{
		case Keyboard::A:
			if (onWallRight) {
				speed.y = -5;
				speed.x = -8;
				onWallRight = false;
			} else if (inAir) {
				speed.x = -2;
			} else {
				speed.x = -5;
			}			
			break;
		case Keyboard::D:
			if (onWallLeft) {
				speed.y = -5;
				speed.x = 8;
				onWallLeft = false;
			}
			else if (inAir) {
				speed.x = 2;
			}
			else {
				speed.x = 5;
			}
			break;
		case Keyboard::Space:
			if (!inAir || true) {
				speed.y = -5;
				inAir = true;
			}
			break;
		case Keyboard::S:
			break;
		default:
			break;
		}
	}
	if (event.type == Event::KeyReleased) {
		if (key == Keyboard::W) {
		}
		if (key == Keyboard::D || key == Keyboard::A) {
			speed.x = 0;
		}
	}
}

Player::~Player() {
}
