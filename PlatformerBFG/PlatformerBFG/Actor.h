#pragma once
#include <SFML/Graphics.hpp>
#include "Updatable.h"

using namespace sf;

/*
Базовый класс, для всех объектов на сцене
*/
class Actor: public Updatable {
public:
	virtual void draw(RenderWindow& window) = 0;
};