#include "Scene.h"
#include <iostream>

using std::vector;
using namespace sf;

void Scene::add(Actor* actor) {
	actors.push_back(actor);
}

void Scene::add(vector<Actor*> actors) {
	for (Actor* actor : actors) {
		add(actor);
	}
}

void Scene::draw(RenderWindow &window) {
	window.clear();
	for (auto actor : actors) {
		actor->draw(window);
	}
	window.display();
}

void Scene::update() {
	deltaTime = clock.getElapsedTime().asMicroseconds()/1000.0;
	currentTime += deltaTime;
	clock.restart();

	for (auto actor : actors) {
		actor->update(currentTime, deltaTime);
	}
}

void Scene::clear() {
	actors.clear();
}

vector<Actor*> Scene::getActors() const {
	return actors;
}