#pragma once

#include <iostream>
#include "Scene.h"
#include "Map.h"
#include "GameConstans.h"

using std::cout;
using std::endl;

class TestLevel : public Updatable {
public:
	TestLevel(Scene* scene);
	void update(float time, float deltaTime) override;
private:
	Map* movingPart = nullptr;
	Tile* floor = nullptr;
	const string pathToMap = "Maps/testMap.map";
	//�������� �������� �� ������, ���������� � ������ � �������
	Vector2f movingDir = Vector2f(-2 * TILE_SIZE, 0);
};

