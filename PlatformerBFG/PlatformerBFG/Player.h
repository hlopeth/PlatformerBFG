#pragma once
#include <SFML/Graphics.hpp>
#include "KeyListner.h"
#include "PhysicsActor.h"
#include "GameConstans.h"

using namespace sf;

class Player : public PhysicsActor, public KeyListner, public Collidable
{
public:
	Player();
	Player(Vector2f position);
	void update(float time, float deltaTime) override;
	void draw(RenderWindow& window) override;
	RectangleShape getCollisionBox() override;
	void onCollide(RectangleShape collisionBox) override;
	void keyEvent(Event event) override;
	~Player();
private:
	RectangleShape rect;
	Vector2u screenSize;
	bool inAir = true;
};

