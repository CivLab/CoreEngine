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

void World::kill(IObject &)
{
}

void World::resolveConflicts()
{
}

void World::calculateExpectedEndPosition(IObject &)
{
}

bool World::tryToMove(IObject &)
{
	return true;
}

void World::move(IObject &)
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

bool World::isNotMovingInWalls(IObject& myObject)
{
	if (walls.size() == 0)
	{
		return true;
	}
	IElement* myElement = myObject.getElement();

	for (auto pWall : walls)
	{
		IElement* pWallElem = pWall->getElement();
		if (myElement->collideWith(*pWallElem))
		{
			return false;
		}
	}
	return true;
}

void World::addCharacter(IObject & myObject)
{
	characters.push_back(&myObject);
}

void World::addEnemy(IObject &myObject)
{
	enemies.push_back(&myObject);
}

void World::addProjectile(IObject &myObject)
{
	projectiles.push_back(&myObject);
}

void World::addWall(IObject &myObject)
{
	walls.push_back(&myObject);
}
