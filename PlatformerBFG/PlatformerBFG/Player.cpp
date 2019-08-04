#include "Player.h"

Player::Player()
{
	rect.setFillColor(Color::Red);
	rect.setSize(Vector2f(20, 40));
	rect.setPosition(Vector2f(0, 0));
}

void Player::update(float time, float deltaTime) {
	rect.move(moveDir * deltaTime * speed);

	if (rect.getPosition().x < 0) {
		rect.move(Vector2f(-rect.getPosition().x, 0));
	}
	if (rect.getPosition().x + rect.getSize().x > screenSize.x) {
		rect.move(Vector2f(screenSize.x - rect.getPosition().x - rect.getSize().x, 0));
	}
	if (rect.getPosition().y < 0) {
		rect.move(Vector2f(0, -rect.getPosition().y));
	}
	if (rect.getPosition().y + rect.getSize().y > screenSize.y) {
		rect.move(Vector2f(0, screenSize.y - rect.getPosition().y - rect.getSize().y));
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
		case Keyboard::W:
			moveDir.y = -1;
			break;
		case Keyboard::S:
			moveDir.y = 1;
			break;
		case Keyboard::A:
			moveDir.x = -1;
			break;
		case Keyboard::D:
			moveDir.x = 1;
			break;
		default:
			break;
		}
	}
	if (event.type == Event::KeyReleased) {
		if (key == Keyboard::W || key == Keyboard::S) {
			moveDir.y = 0;
		}
		if (key == Keyboard::D || key == Keyboard::A) {
			moveDir.x = 0;
		}
	}
}

Player::~Player()
{
}
