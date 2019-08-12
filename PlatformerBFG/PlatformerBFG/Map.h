#pragma once
#include <vector>
#include "Tile.h"
#include "string"

using std::vector;
using std::string;

class Map {
public:
	Map();
	Map(const vector<Tile> tiles);
	vector<Actor*> getActors();
	static Map loadMapFromFile(string filename);
private:
	vector<Tile> _tiles;
};


extern Map defaultMap;