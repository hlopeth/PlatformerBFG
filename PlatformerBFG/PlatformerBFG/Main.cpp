#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Actor.h"
#include "InputProvider.h"
#include "Player.h"
#include "PhysicsActor.h"
#include "Map.h"
#include "MapGenerator.h"

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
		PhysicsActor::update(time, deltaTime);

		float timeInSeconds = deltaTime * 0.001;
		Vector2f delta = speed * (timeInSeconds * PIXEL_IN_METER);
		move(delta);
		
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
	srand(time(NULL));
	RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	Scene scene;
	InputProvider inputProvider;

	Circle *shape = new Circle(10);
	shape->setFillColor(Color::Yellow);
	shape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	scene.addActor(shape);

	MapGenerator* mapGenerator = new MapGenerator(100, 600, 600-TILE_SIZE, Vector2f(-100, 0), &scene);
	scene.addUpdatable(mapGenerator);

	Player player(Vector2f(200, 50));
	scene.addActor(&player);
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