#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	rect.setFillColor(Color::Red);
	rect.setSize(Vector2f(TILE_SIZE, 2 * TILE_SIZE));
	rect.setPosition(Vector2f(0, 0));
	mass = 0.8;
}

Player::Player(Vector2f position) : Player() {
	rect.setPosition(position);
}

void Player::update(float time, float deltaTime) {
	PhysicsActor::update(time, deltaTime);

	float timeInSeconds = deltaTime * 0.001;
	Vector2f delta = speed * (timeInSeconds * PIXEL_IN_METER);
	rect.move(delta);
	inAir = true;
}

void Player::draw(RenderWindow& window) {
	window.draw(rect);
	screenSize = window.getSize();
}

RectangleShape Player::getCollisionBox() {
	return rect;
}

void Player::onCollide(RectangleShape collisionBox) {
	Vector2f collideMove = Collidable::getCollideMove(getCollisionBox(), collisionBox);
	if (collideMove.y < 0) {
		speed.y = 0;
		inAir = false;
	}
	rect.move(collideMove);
}

void Player::keyEvent(Event event) {
	auto key = event.key.code;
	if (event.type == Event::KeyPressed) {
		switch (key)
		{
		case Keyboard::A:
			speed.x = -5;
			break;
		case Keyboard::D:
			speed.x = 5;
			break;
		case Keyboard::Space:
			if (!inAir) {
				speed.y = -3.8;
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
