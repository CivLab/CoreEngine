#include "Weapon.h"



Weapon::Weapon()
{
}

Weapon::Weapon(std::string name, int damage, int firingRate)
{
	m_name = name;
	m_damage = damage;
	m_firingRate = firingRate;
}


Weapon::~Weapon()
{
}
