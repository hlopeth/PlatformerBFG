#pragma once
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Tile.h"

using json = nlohmann::json;
using std::vector;
using std::string;
using std::ifstream;

class Map {
public:
	Map();
	Map(const vector<Tile*> tiles);
	vector<Actor*> getActors();
	static bool loadMapFromFile(string filename, Map* &result);
	vector<Tile*> tiles;
	~Map();
};


extern Map defaultMap;