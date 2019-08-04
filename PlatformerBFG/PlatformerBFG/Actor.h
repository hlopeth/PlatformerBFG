#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
Базовый класс, для всех объектов на сцене
*/
class Actor {
public:
	virtual void update(float time, float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
};