#include "MapGenerator.h"
#include <iostream>

MapGenerator::MapGenerator(int leftBorder, int rightBorder, float y, Vector2f speed, Scene* scene) {
	chanceToSpawnBlock = 15;
	this->width = (rightBorder - leftBorder) / TILE_SIZE + 1;
	this->mapLeftBorder = leftBorder;
	this->mapRightBorder = rightBorder;
	this->speed = speed;
	this->y = y;
	this->scene = scene;
	this->tilesInMap = abs(rightBorder - leftBorder) / TILE_SIZE + 1;
	floor = new Tile(Vector2f(0, y), Vector2f(tilesInMap * TILE_SIZE, TILE_SIZE));
	initMap();
}

void MapGenerator::initMap() {
	scene->addActor(floor);
}

void MapGenerator::update(float time, float deltaTime) {
	Vector2f offset = speed * deltaTime * 0.001f;
	offsetSum += abs(offset.x);
	for (auto it = tiles.begin(); it < tiles.end(); it++) {
		(*it)->move(offset);
	}

	if (deleteNoNeedTiles()) {
		speed.x += -10;
	}
	
	bool timeToRoll = offsetSum > TILE_SIZE;
	if (timeToRoll) {
		if (rand() % 100 < chanceToSpawnBlock) {
			Vector2f tileSize = Vector2f(TILE_SIZE, TILE_SIZE * (rand() % 2 + 1));
			Tile* newTile = new Tile(Vector2f(mapRightBorder, y - tileSize.y), tileSize);
			tiles.push_back(newTile);
			scene->addActor(newTile);
		}
		offsetSum = 0;
	}
}

bool MapGenerator::deleteNoNeedTiles() {
	if (tiles.size() > 0) {
		Tile firstTile = *tiles[0];
		float firstTileRightBorder = firstTile.getPosition().x + firstTile.getSize().x;
		if (firstTileRightBorder < mapLeftBorder) {
			scene->removeActor(tiles[0]);
			delete tiles[0];
			tiles.erase(tiles.begin());
			return true;
		}
	}
	return false;
}