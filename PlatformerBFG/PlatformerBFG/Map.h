#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Tile.h"

using std::vector;
using std::string;
using std::ifstream;

class Map {
public:
	Map();
	Map(const vector<Tile*> tiles);
	vector<Actor*> getActors();
	static bool loadMapFromFile(string filename, Map* &result, float tileCoordY);
	vector<Tile*> tiles;
	~Map();
};


extern Map defaultMap;