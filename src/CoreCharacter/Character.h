#pragma once
#include "Weapon.h"
#include <iostream>

class Character
{
public:
	Character();
	Character(std::string name, int life = 100, int damage = 10);

	~Character();

	enum Statut
	{
		DEAD = 0,
		ALIVE = 1,
		REMOVED = 2
	};

	bool isAlive() { return m_statut == ALIVE; }

	void updateStatut();
	void isHit(int damage);
	void isHealed(int heal);

	int getLife() { return m_life; }
	int getMaxLife() { return m_maxLife; }
	
private:
	std::string m_ID;
	std::string m_name;
	Statut m_statut;
	int m_life;
	int m_maxLife;
	int m_damage;
};

