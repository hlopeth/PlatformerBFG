#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace sf;

/*
Базовый класс, для всех объектов на сцене
*/
class Actor {
public:
	virtual void update() = 0;
	virtual void draw(RenderWindow& window) const = 0;
};