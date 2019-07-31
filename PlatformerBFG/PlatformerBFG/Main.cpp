#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;
using namespace sf;

//precicates
void poolEvents(RenderWindow& window);
void updateScene(Scene& scene);

//constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Vector2f moveDir = Vector2f(0.1f, 0.1f);

int main()
{
	RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	Scene scene;

	CircleShape *shape = new CircleShape(10.f);
	shape->setFillColor(Color::Green);
	shape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	scene.add(shape);


	while (window.isOpen())
	{
		poolEvents(window);
		updateScene(scene);
		scene.draw(window);
	}

	scene.clear();

	return 0;
}

void poolEvents(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void updateScene(Scene& scene) {
	CircleShape*circle = (CircleShape*)scene.items[0];
	circle->move(moveDir);

	if (circle->getPosition().x < 0) {
		circle->move(Vector2f(-circle->getPosition().x, 0));
		moveDir.x *= -1;
		moveDir *= 1.1f;
	}
	if(circle->getPosition().x + circle->getRadius() * 2 > SCREEN_WIDTH) {
		circle->move(Vector2f(SCREEN_WIDTH - circle->getPosition().x - circle->getRadius() * 2, 0));
		moveDir.x *= -1;
		moveDir *= 1.1f;
	}
	if (circle->getPosition().y < 0) {
		circle->move(Vector2f(0, -circle->getPosition().y));
		moveDir.y *= -1;
		moveDir *= 1.1f;
	}
	if(circle->getPosition().y + circle->getRadius() * 2 > SCREEN_HEIGHT) {
		float delta = (circle->getPosition().y + circle->getRadius() * 2) - SCREEN_HEIGHT;
		circle->move(Vector2f(0, SCREEN_HEIGHT - circle->getPosition().y - circle->getRadius() * 2));
		moveDir.y *= -1;
		moveDir *= 1.1f;
	}

	moveDir.x = min(moveDir.x, 4.f);
	moveDir.y = min(moveDir.y, 4.f);
}