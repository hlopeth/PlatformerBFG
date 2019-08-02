#pragma once
#include <vector>
#include "Actor.h"

using std::vector;
using namespace sf;

class Scene {
public:
	vector<Actor*> actors;
	
	void add(Actor* item) {
		actors.push_back(item);
	}

	void draw(RenderWindow &window) {
		window.clear();
		for (auto actor : actors) {
			actor->draw(window);
		}
		window.display();
	}

	void update() {
		for (auto actor : actors) {
			actor->update();
		}
	}

	void clear() {
		for (auto item : actors)
			delete(item);
		actors.clear();
	}
};
