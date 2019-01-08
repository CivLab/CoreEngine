#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "IDecor.h"
#include "IMovingElement.h"
#include "IObject.h"
#include "IElement.h"

class IWorld
{
public:
	IWorld() {};
	virtual ~IWorld() {};

	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void checkCurrentSituation() = 0;
	virtual void clean() = 0;

	virtual void kill(IObject&) = 0;
	virtual void resolveConflicts() = 0;
	virtual void calculateExpectedEndPosition(IObject&) = 0;

	virtual bool tryToMove(IObject&) = 0;
	virtual bool isNotMovingInWalls(IObject&) = 0;
	virtual void move(IObject&) = 0;
	virtual void moveCharacters() = 0;
	virtual void moveEnemies() = 0;
	virtual void moveProjectiles() = 0;

	virtual void addCharacter(IObject&)= 0;
	virtual void addEnemy(IObject&) = 0;
	virtual void addProjectile(IObject&) = 0;
	virtual void addWall(IObject&) = 0;

protected:
	std::vector<IObject*> characters;
	std::vector<IObject*> enemies;
	std::vector<IObject*> projectiles;
	std::vector<IObject*> walls;

	bool exists;
};

