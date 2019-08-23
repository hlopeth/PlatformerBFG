#include "Scene.h"
#include <iostream>

using std::vector;
using namespace sf;

void Scene::addActor(Actor* actor) {
	actors.push_back(actor);
	if (Collidable* c = dynamic_cast<Collidable*>(actor)) {
		collidableActors.push_back(dynamic_cast<Collidable*>(actor));
	}
}

void Scene::removeActor(Actor* actor) {
	for (auto it = actors.begin(); it < actors.end(); it++) {
		if (*it == actor) {
			actors.erase(it);
			break;
		}
	}

	if (Collidable * c = dynamic_cast<Collidable*>(actor)) {
		for (auto it = collidableActors.begin(); it < collidableActors.end(); it++) {
			if (*it == c) {
				collidableActors.erase(it);
				break;
			}
		}
	}
}

void Scene::addActors(vector<Actor*> actors) {
	for (Actor* actor : actors) {
		addActor(actor);
	}
}

void Scene::addUpdatable(Updatable* updatable) {
	updatables.push_back(updatable);
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

	for (auto updatable : updatables) {
		updatable->update(currentTime, deltaTime);
	}

	for (auto actor : actors) {
		actor->update(currentTime, deltaTime);
	}

	checkCollisions();
}

void Scene::checkCollisions() {
	int n = collidableActors.size();
	RectangleShape collisionBox1;
	RectangleShape collisionBox2;
	for (int i = 0; i < n; i++) {
		collisionBox1 = collidableActors[i]->getCollisionBox();
		for (int j = i + 1; j < n; j++) {
			collisionBox2 = collidableActors[j]->getCollisionBox();
			if (Collidable::colliding(collisionBox1, collisionBox2)) {
				collidableActors[i]->onCollide(collisionBox2);
				collidableActors[j]->onCollide(collisionBox1);
			}
		}
	}
}

void Scene::clear() {
	actors.clear();
	collidableActors.clear();
	updatables.clear();
}

vector<Actor*> Scene::getActors() const {
	return actors;
}