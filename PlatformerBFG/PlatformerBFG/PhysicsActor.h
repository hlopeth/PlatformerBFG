#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionActor.h"

using namespace sf;

const unsigned int PIXEL_IN_METER = 100;
const Vector2f gravityAccseleration = Vector2f(0, 9.8);

class PhysicsActor : public Actor {
public:
	bool usesGravity = true;
protected:
	//скорость в м/с
	Vector2f speed = Vector2f(0,0);
	//ускорение в м/с^2
	Vector2f accseleration = Vector2f(0,0);
	//масса в кг
	float mass = 0;

	//обновляет скорость, возвращает как нужно передвинуть актора в пикселях
	void update(float time, float deltaTime) {
		float timeInSeconds = deltaTime * 0.001;
		Vector2f accselerationSum = accseleration;
		if (usesGravity)
			accselerationSum += gravityAccseleration;

		speed += accselerationSum * timeInSeconds;
	}
};