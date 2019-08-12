#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	rect.setFillColor(Color::Red);
	rect.setSize(Vector2f(25, 50));
	rect.setPosition(Vector2f(0, 0));
	std::cout << rect.getPosition().x << std::endl;
}

Player::Player(Vector2f position) : Player() {
	rect.setPosition(position);
	std::cout << rect.getPosition().x << std::endl;
}

void Player::update(float time, float deltaTime) {
	Vector2f delta = updatePhysics(deltaTime);
	rect.move(delta);

	if (rect.getPosition().x < 0) {
		rect.move(Vector2f(-rect.getPosition().x, 0));
		onWallLeft = true;
	}

	if (rect.getPosition().x + rect.getSize().x > screenSize.x) {
		rect.move(Vector2f(screenSize.x - rect.getPosition().x - rect.getSize().x, 0));
		onWallRight = true;
	}

	if (rect.getPosition().y < 0) {
		rect.move(Vector2f(0, -rect.getPosition().y));
	}

	if (rect.getPosition().y + rect.getSize().y > screenSize.y) {
		rect.move(Vector2f(0, screenSize.y - rect.getPosition().y - rect.getSize().y));
		inAir = false;
	}
}

void Player::draw(RenderWindow& window) {
	window.draw(rect);
	screenSize = window.getSize();
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
			if (!inAir) {
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
