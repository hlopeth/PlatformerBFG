#pragma once
#include "Map.h"
#include "GameConstans.h"
#include "Scene.h"

class MapGenerator: public Map, public Updatable {
public:
	MapGenerator(int leftBorder, int rightBorder, float y, Vector2f speed, Scene* scene);
	void update(float time, float deltaTime);
private:
	void initMap();
	//true если удалил какой либо таил
	bool deleteNoNeedTiles();
	Tile* floor;
	//ширина карты в тайлах
	int width;
	//левая граница в пикселях
	int mapLeftBorder;
	//правая граница в пикселях
	int mapRightBorder;
	int tilesInMap;
	float chanceToSpawnBlock;
	float y;
	Scene* scene;
	//скорость в пикселях в секунду
	Vector2f speed = Vector2f(0,0);
	float offsetSum = 0;
};

