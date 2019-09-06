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

bool Map::loadMapFromFile(string filename, Map* &result, float tileCoordY) {
	ifstream in(filename);
	if (!in.is_open()) {
		return false;
	}

	result = new Map();
	const int maxLineSize = 100;
	char line[maxLineSize];
	while (!in.eof())
	{
		in.getline(line, 100);
		int tileCoordX = 0;

		for (int i = 0; i < maxLineSize; i++) {
			if (line[i] >= '0' && line[i] <= '9') {
				tileCoordX = tileCoordX * 10 + line[i] - '0';
			}
			else {
				//коментарий
				if (line[i] == '#') {
					break;
				}
				else if (line[i] == '\0') {
					if (i > 0) {
						result->tiles.push_back(new Tile(Vector2f(tileCoordX, tileCoordY)));
						break;
					}
					else {
						break;
					}
				}
				else {
					delete result;
					return false;
				}
			}
		}
	}

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


