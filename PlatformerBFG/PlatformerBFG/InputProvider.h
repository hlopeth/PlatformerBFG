#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "KeyListner.h"

using namespace sf;
using std::vector;

class InputProvider {
public:
	void registerListner(KeyListner*);
	void unregisterListner(KeyListner*);
	void poolEvents(RenderWindow&);
private:
	vector<KeyListner*> listners;
	Event event;
};