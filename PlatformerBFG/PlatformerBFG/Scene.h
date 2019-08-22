#pragma once
#include <vector>
#include <typeinfo>
#include <SFML/System.hpp>
#include "Actor.h"
#include "CollisionActor.h"

using std::vector;
using std::type_info;
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
	vector<Collidable*> collidableActors;
	Clock clock;
	//Сколько времени прошло с предыдущего update() в милисикундах
	float deltaTime = 0;
	//Текущее время в милисикундах
	float currentTime = 0;
private:
	void checkCollisions();
	const type_info& collidableTypeInfo = typeid(Collidable);
};


