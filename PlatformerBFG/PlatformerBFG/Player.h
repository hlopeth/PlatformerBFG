#pragma once
#include <SFML/Graphics.hpp>
#include "KeyListner.h"
#include "Actor.h"

using namespace sf;

class Player : public Actor, public KeyListner
{
public:
	Player();
	void update(float time, float deltaTime) override;
	void draw(RenderWindow& window) override;
	void keyEvent(Event event) override;
	~Player();
private:
	RectangleShape rect;
	Vector2f moveDir;
	float speed = 0.2;
	Vector2u screenSize;
};

