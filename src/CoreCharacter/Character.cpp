#include "Character.h"



Character::Character() : Character("")
{
}

Character::Character(std::string name, int life, int damage)
{
	m_name = name;
	m_ID = name;
	m_life = life;
	m_maxLife = life;
	m_damage = damage;
	m_statut = ALIVE;
}


Character::~Character()
{
}

void Character::updateStatut()
{
	m_statut = m_life > 0 ? ALIVE : DEAD;
}

void Character::isHit(int damage)
{
	m_life = (fmax(0, m_life - damage));
	updateStatut();
}

void Character::isHealed(int heal)
{
	m_life = fmin(m_maxLife, m_life + heal);
}
