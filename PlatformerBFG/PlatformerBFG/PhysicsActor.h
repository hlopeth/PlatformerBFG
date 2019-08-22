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
	//�������� � �/�
	Vector2f speed = Vector2f(0,0);
	//��������� � �/�^2
	Vector2f accseleration = Vector2f(0,0);
	//����� � ��
	float mass = 0;

	//��������� ��������, ���������� ��� ����� ����������� ������ � ��������
	void update(float time, float deltaTime) {
		float timeInSeconds = deltaTime * 0.001;
		Vector2f accselerationSum = accseleration;
		if (usesGravity)
			accselerationSum += gravityAccseleration;

		speed += accselerationSum * timeInSeconds;
	}
};