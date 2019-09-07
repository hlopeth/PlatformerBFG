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

bool Map::loadMapFromFile(string filename, Map* &result) {
	ifstream input(filename);
	if (!input.is_open()) {
		return false;
	}
	json j;
	vector<Tile*> tiles;
	input >> j;
	for (auto& element : j["array"]) {
		auto jsonTile = element["Tile"];
		Vector2f position(jsonTile["Position"]["X"], jsonTile["Position"]["Y"]);
		Vector2f scale(jsonTile["Scale"]["Width"], jsonTile["Scale"]["Height"]);
		tiles.push_back(new Tile(position, scale));
	}
	result = new Map(tiles);
	return true;
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
		new Tile(Vector2f(0, 0), Vector2f(width, 1)),
		new Tile(Vector2f(0, 1), Vector2f(1, height)),
		new Tile(Vector2f(width, 0), Vector2f(1, height)),
		new Tile(Vector2f(1, height), Vector2f(width, 1)),
		new Tile(Vector2f(1,  7),Vector2f(10, 1))
	}
);


