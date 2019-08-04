#pragma once
#include <SFML/Graphics.hpp>

using sf::Event;

class KeyListner {
public:
	virtual void keyEvent(Event event) = 0;
};