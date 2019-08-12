#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Actor.h"
#include "InputProvider.h"
#include "Player.h"
#include "PhysicsActor.h"
#include "Map.h"

using namespace std;
using namespace sf;

//constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


class Circle : public PhysicsActor, public CircleShape {
public:
	Circle(int r) : CircleShape(r) {
		speed.x = 5;
	}
	void update(float time, float deltaTime) override {
		move(updatePhysics(deltaTime));
		
		if (getPosition().x < 0) {
			move(Vector2f(-getPosition().x, 0));
			speed.x *= -1;
		}
		if (getPosition().x + getRadius() * 2 > SCREEN_WIDTH) {
			move(Vector2f(SCREEN_WIDTH - getPosition().x - getRadius() * 2, 0));
			speed.x *= -1;
		}
		if (getPosition().y < 0) {
			move(Vector2f(0, -getPosition().y));
		}
		if (getPosition().y + getRadius() * 2 > SCREEN_HEIGHT) {
			move(Vector2f(0, SCREEN_HEIGHT - getPosition().y - getRadius() * 2));
			speed.y *= -1;
		}
	}
	
	virtual void draw(RenderWindow& window) {
		window.draw(*this);
	}
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

	scene.add(defaultMap.getActors());

	Player player(Vector2f(50, 50));
	scene.add(&player);
	inputProvider.registerListner(&player);

	//initial draw
	scene.draw(window);

	while (window.isOpen())
	{
		scene.update();
		scene.draw(window);
		inputProvider.poolEvents(window);
	}
	scene.clear();
	return 0;
}
