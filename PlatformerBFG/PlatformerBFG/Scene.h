#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;
using namespace sf;

class Scene {
public:
	vector<Shape*> items;


	void add(Shape* item) {
		items.push_back(item);
	}

	void draw(RenderWindow &window) {
		window.clear();
		for (auto item : items) {
			window.draw(*item);
		}
		window.display();
	}

	void clear() {
		for (auto item : items)
			delete(item);
		items.clear();
	}
};
