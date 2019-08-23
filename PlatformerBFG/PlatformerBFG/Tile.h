#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionActor.h"
#include "GameConstans.h"

class Tile : public Collidable, public Actor {
public:
	Tile();
	Tile(Vector2f position, Vector2f size = Vector2f(TILE_SIZE, TILE_SIZE));
	void update(float time, float deltaTime) override;
	void draw(RenderWindow& window) override;
	RectangleShape getCollisionBox() override;
	void onCollide(RectangleShape collisionBox);
	void setPosition(Vector2f& position);
	void move(Vector2f offset);
	Vector2f getBottomLeft();
	Vector2f getTopRight();
	Vector2f getSize();
	Vector2f getPosition();
private:
	RectangleShape rect = RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE));
};