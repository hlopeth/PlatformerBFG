#pragma once
#include <vector>
#include "Tile.h"
#include "string"

using std::vector;
using std::string;

class Map {
public:
	Map();
	Map(const vector<Tile*> tiles);
	vector<Actor*> getActors();
	static Map loadMapFromFile(string filename);
	~Map();
protected:
	vector<Tile*> tiles;
};


extern Map defaultMap;