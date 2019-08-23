#include "Map.h"

Map::Map() {
}

Map::Map(const vector<Tile*> tiles) {
	this->tiles.clear();
	for (auto tile : tiles) {
		this->tiles.push_back(tile);
	}
}

vector<Actor*> Map::getActors() {
	vector<Actor*> actors;
	for (int i = 0; i < tiles.size(); i++) {
		actors.push_back(tiles[i]);
	}

	return actors;
}

Map Map::loadMapFromFile(string filename) {
	return Map();
}

Map::~Map() {
	for (Tile* tile : tiles) {
		delete tile;
	}
}

const int height = 23;
const int width = 31;
Map defaultMap(
	{
		new Tile(Vector2f(0, 0), Vector2f(TILE_SIZE * width, TILE_SIZE)),
		new Tile(Vector2f(0, TILE_SIZE), Vector2f(TILE_SIZE, height * TILE_SIZE)),
		new Tile(Vector2f(TILE_SIZE* width, 0), Vector2f(TILE_SIZE, TILE_SIZE * height)),
		new Tile(Vector2f(TILE_SIZE, TILE_SIZE* height), Vector2f(TILE_SIZE* width, TILE_SIZE)),
		new Tile(Vector2f(TILE_SIZE, TILE_SIZE * 7),Vector2f(TILE_SIZE * 10, TILE_SIZE))
	}
);


