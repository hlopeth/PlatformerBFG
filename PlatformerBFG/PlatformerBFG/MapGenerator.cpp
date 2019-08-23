#include "MapGenerator.h"

MapGenerator::MapGenerator(int leftBorder, int rightBorder, float y, Vector2f speed, Scene* scene) {
	this->width = (rightBorder - leftBorder) / TILE_SIZE + 1;
	this->mapLeftBorder = leftBorder;
	this->mapRightBorder = rightBorder;
	this->speed = speed;
	this->y = y;
	this->scene = scene;
	this->tilesInMap = abs(rightBorder - leftBorder) / TILE_SIZE + 1;
	initMap();
}

void MapGenerator::initMap() {
	int x = mapLeftBorder;
	for (int i = 0; i < tilesInMap; i++, x+= TILE_SIZE) {
		tiles.push_back(new Tile(Vector2f(x, y)));
	}
	scene->addActors(getActors());
}

void MapGenerator::update(float time, float deltaTime) {
	Vector2f offset = speed * deltaTime * 0.001f;
	for (auto it = tiles.begin(); it < tiles.end(); it++) {
		(*it)->move(offset);
	}
	Tile firstTile = *tiles[0];
	float firstTileRightBorder = firstTile.getPosition().x + firstTile.getSize().x;
	if (firstTileRightBorder < mapLeftBorder) {
		scene->removeActor(tiles[0]);
		delete tiles[0];
		tiles.erase(tiles.begin());

		Tile lastTile = *tiles[tiles.size()-1];
		int lastTileRightBorder = lastTile.getPosition().x + lastTile.getSize().x;
		Vector2f tileSize = Vector2f(TILE_SIZE, TILE_SIZE * (rand() % 5 + 1));
		tiles.push_back(new Tile(Vector2f(lastTileRightBorder, y - tileSize.y + 1), tileSize));
		scene->addActor(tiles[tiles.size() - 1]);
	}
}
