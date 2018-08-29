#pragma once

#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string name, int damage = 10, int firingRate = 1);
	~Weapon();

private:
	std::string m_name;
	int m_damage;
	int m_firingRate;
};

