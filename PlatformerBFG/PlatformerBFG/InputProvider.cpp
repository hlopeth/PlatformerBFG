#include "InputProvider.h"

void InputProvider::registerListner(KeyListner* keyListner) {
	listners.push_back(keyListner);
}

void InputProvider::unregisterListner(KeyListner* keyListner) {
	auto it = listners.begin();
	while (it != listners.end()) {
		if (*it == keyListner)
			listners.erase(it);
		else
			it++;
	}
}

void InputProvider::poolEvents(RenderWindow& window) {
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
		case Event::KeyReleased:
			for (auto listner : listners)
				listner->keyEvent(event);
			break;
		default:
			break;
		}
	}
}