#pragma once
#include <SFML/Graphics.hpp>
#include "Updatable.h"

using namespace sf;

/*
������� �����, ��� ���� �������� �� �����
*/
class Actor: public Updatable {
public:
	virtual void draw(RenderWindow& window) = 0;
};