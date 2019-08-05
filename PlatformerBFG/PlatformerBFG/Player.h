#pragma once
#include <SFML/Graphics.hpp>
#include "KeyListner.h"
#include "PhysicsActor.h"

using namespace sf;

class Player : public PhysicsActor, public KeyListner
{
public:
	Player();
	void update(float time, float deltaTime) override;
	void draw(RenderWindow& window) override;
	void keyEvent(Event event) override;
	~Player();
private:
	RectangleShape rect;
	Vector2u screenSize;
	bool inAir = true;
	bool onWallLeft = false;
	bool onWallRight = false;
};

