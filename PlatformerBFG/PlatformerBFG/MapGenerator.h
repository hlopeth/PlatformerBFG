#pragma once
#include "Map.h"
#include "GameConstans.h"
#include "Scene.h"

class MapGenerator: public Map, public Updatable {
public:
	MapGenerator(int leftBorder, int rightBorder, float y, Vector2f speed, Scene* scene);
	void update(float time, float deltaTime);
private:
	void initMap();
	//true ���� ������ ����� ���� ����
	bool deleteNoNeedTiles();
	Tile* floor;
	//������ ����� � ������
	int width;
	//����� ������� � ��������
	int mapLeftBorder;
	//������ ������� � ��������
	int mapRightBorder;
	int tilesInMap;
	float chanceToSpawnBlock;
	float y;
	Scene* scene;
	//�������� � �������� � �������
	Vector2f speed = Vector2f(0,0);
	float offsetSum = 0;
};

