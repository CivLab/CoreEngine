#include "Object.h"

Object::Object()
{
}

Object::Object(std::string name, sf::CircleShape & shape, MovingElement movingElement)
{
	m_name = name;
	m_shape = &shape;
	m_Character = new Character(name);
}


Object::~Object()
{
}

void Object::setTexture(const char * file)
{
	if (!m_texture.loadFromFile(file))
	{
		m_shape->setFillColor(sf::Color::Red);
	}
	else
	{
		m_shape->setTexture(&m_texture);
	}
}
