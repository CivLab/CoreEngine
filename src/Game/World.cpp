#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::initialize()
{
}

void World::update()
{
}

void World::checkCurrentSituation()
{
}

void World::clean()
{
}

void World::kill(IMovingElement &)
{
}

void World::resolveConflicts()
{
}

void World::calculateExpectedEndPosition(IMovingElement &)
{
}

bool World::tryToMove(IMovingElement &)
{
	return true;
}

void World::move(IMovingElement &)
{
}

void World::moveCharacters()
{
}

void World::moveEnemies()
{
}

void World::moveProjectiles()
{
}

void World::initializePlayer()
{
	auto myPlayerChar = Character("Player1", 100, 100);
	auto myPlayerElem = Element();
}
