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
	virtual void kill(IElement &) override;
	virtual void resolveConflicts() override;
	virtual void calculateExpectedEndPosition(IElement &) override;
	virtual bool tryToMove(IElement &) override;
	virtual void move(IElement &) override;
	virtual void moveCharacters() override;
	virtual void moveEnemies() override;
	virtual void moveProjectiles() override;
	
	virtual bool isNotMovingInWalls(IElement &) override;
	virtual void addCharacter(IObject &) override;
	virtual void addEnemy(IObject &) override;
	virtual void addProjectile(IObject &) override;
	virtual void addWall(IObject &) override;
	//additional Methods
	void initializePlayer();


};

