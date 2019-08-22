#include "Tile.h"

Tile::Tile() {
	rect.setFillColor(Color::Green);
}

Tile::Tile(Vector2f position, Vector2f size): Tile() {
	rect.setPosition(position);
	rect.setSize(size);
}

void Tile::update(float time, float deltaTime) {
}

void Tile::draw(RenderWindow& window) {
	window.draw(rect);
}

RectangleShape Tile::getCollisionBox() {
	return rect;
}

void Tile::onCollide(RectangleShape collisionBox) {

}

void Tile::setPosition(Vector2f& position) {
	rect.setPosition(position);
}

Vector2f Tile::getBottomLeft() {
	return Vector2f(rect.getPosition().x, rect.getPosition().y + rect.getSize().y);
}

Vector2f Tile::getTopRight() {
	return Vector2f(rect.getPosition().x + rect.getSize().x, rect.getPosition().y);
}

Vector2f Tile::getSize() {
	return rect.getSize();
}

Vector2f Tile::getPosition() {
	return rect.getPosition();
}