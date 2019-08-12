#pragma once
#include <vector>
#include <SFML/System.hpp>
#include "Actor.h"

using std::vector;
using namespace sf;

class Scene {
public:
	void add(Actor*);
	void add(vector<Actor*>);
	void draw(RenderWindow&);
	void update();
	void clear();
	vector<Actor*> getActors() const;
protected:
	vector<Actor*> actors;
	Clock clock;
	//Сколько времени прошло с предыдущего update() в милисикундах
	float deltaTime = 0;
	//Текущее время в милисикундах
	float currentTime = 0;
};


