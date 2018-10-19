#pragma once
#include "../WorldInterface/IWorld.h"
#include "../CoreStructure/MovingElement.h"
#include "../CoreCharacter/Character.h"

class World : IWorld
{
public:
	World();
	~World();

	// Inherited via IWorld
	virtual void initialize() override;
	virtual void update() override;
	virtual void checkCurrentSituation() override;
	virtual void clean() override;
	virtual void kill(IMovingElement &) override;
	virtual void resolveConflicts() override;
	virtual void calculateExpectedEndPosition(IMovingElement &) override;
	virtual bool tryToMove(IMovingElement &) override;
	virtual void move(IMovingElement &) override;
	virtual void moveCharacters() override;
	virtual void moveEnemies() override;
	virtual void moveProjectiles() override;

	//additional Methods
	void initializePlayer();
};

