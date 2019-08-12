#include "Map.h"

Map::Map() {
}

Map::Map(const vector<Tile> tiles) {
	_tiles.clear();
	for (auto tile : tiles) {
		_tiles.push_back(tile);
	}
}

vector<Actor*> Map::getActors() {
	vector<Actor*> actors;
	for (int i = 0; i < _tiles.size(); i++) {
		actors.push_back(&_tiles[i]);
	}

	return actors;
}

Map Map::loadMapFromFile(string filename) {
	return Map();
}

const int height = 20;
const int width = 20;
Map defaultMap(
	{
		Tile(Vector2f(0, 0)),
		Tile(Vector2f(25, 0), Vector2f(25 * width, 25)),
		Tile(Vector2f(0, 25), Vector2f(25, height * 25)),
		Tile(Vector2f(25 * (width + 1), 0)),
		Tile(Vector2f(0, 25 * (height + 1)))
	}
);


