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
	//������� ������� ������ � ����������� update() � ������������
	float deltaTime = 0;
	//������� ����� � ������������
	float currentTime = 0;
};


