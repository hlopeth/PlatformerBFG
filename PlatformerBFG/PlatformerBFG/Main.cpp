#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Actor.h"
#include "InputProvider.h"
#include "Player.h"

using namespace std;
using namespace sf;

//constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


class Circle : public Actor, public CircleShape {
public:
	Circle(int r) : CircleShape(r) {
	}
	void update(float time, float deltaTime) override {
		move(moveDir * speed * deltaTime);
		
		if (getPosition().x < 0) {
			move(Vector2f(-getPosition().x, 0));
			moveDir.x *= -1;
		}
		if (getPosition().x + getRadius() * 2 > SCREEN_WIDTH) {
			move(Vector2f(SCREEN_WIDTH - getPosition().x - getRadius() * 2, 0));
			moveDir.x *= -1;
		}
		if (getPosition().y < 0) {
			move(Vector2f(0, -getPosition().y));
			moveDir.y *= -1;
		}
		if (getPosition().y + getRadius() * 2 > SCREEN_HEIGHT) {
			float delta = (getPosition().y + getRadius() * 2) - SCREEN_HEIGHT;
			move(Vector2f(0, SCREEN_HEIGHT - getPosition().y - getRadius() * 2));
			moveDir.y *= -1;
		}
	}
	
	virtual void draw(RenderWindow& window) {
		window.draw(*this);
	}
private:
	Vector2f moveDir = Vector2f(1, 1);
	float speed = 1;
};

int main()
{
	RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	Scene scene;
	InputProvider inputProvider;

	Circle *shape = new Circle(10);
	shape->setFillColor(Color::Green);
	shape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	scene.add(shape);

	Player player;
	scene.add(&player);
	inputProvider.registerListner(&player);

	while (window.isOpen())
	{
		scene.update();
		scene.draw(window);
		inputProvider.poolEvents(window);
	}
	scene.clear();
	return 0;
}
