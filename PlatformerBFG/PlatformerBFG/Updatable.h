#pragma once

class Updatable {
public:
	virtual void update(float time, float deltaTime) = 0;
};

