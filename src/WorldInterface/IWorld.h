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


	virtual void kill(IMovingElement&) = 0;
	virtual void resolveConflicts() = 0;
	virtual void calculateExpectedEndPosition(IMovingElement&) = 0;

	virtual bool tryToMove(IMovingElement&) = 0;
	virtual void move(IMovingElement&) = 0;
	virtual void moveCharacters() = 0;
	virtual void moveEnemies() = 0;
	virtual void moveProjectiles() = 0;

private:
	std::map<IObject*, IElement*> objectsMap;
	std::vector<IMovingElement*> characters;
	std::vector<IMovingElement*> enemies;
	std::vector<IMovingElement*> projectiles;
	std::vector<IDecor*> walls;
};

