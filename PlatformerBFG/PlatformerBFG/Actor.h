#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
������� �����, ��� ���� �������� �� �����
*/
class Actor {
public:
	virtual void update(float time, float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
};