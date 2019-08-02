#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace sf;

/*
������� �����, ��� ���� �������� �� �����
*/
class Actor {
public:
	virtual void update() = 0;
	virtual void draw(RenderWindow& window) const = 0;
};