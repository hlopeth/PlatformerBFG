#include "TestLevel.h"

TestLevel::TestLevel(Scene* scene) {
	if (Map::loadMapFromFile(pathToMap, movingPart)) {
		scene->addActors(movingPart->getActors());

		Vector2f floorPos = Vector2f(0, SCREEN_HEIGHT/TILE_SIZE - 1);
		Vector2f floorSize = Vector2f(SCREEN_WIDTH / TILE_SIZE + 1, 1);
		floor = new Tile(floorPos, floorSize);
		scene->addActor(floor);

		scene->addUpdatable(this);
	}
	else {
		cout << "failed to load TestLevel from " << pathToMap << endl;
	}
}

void TestLevel::update(float time, float deltaTime) {
	Vector2f move = movingDir * (deltaTime * SECONDS_IN_A_MILISECOND);
	for (auto tile : movingPart->tiles) {
		tile->move(move);
	}
}

