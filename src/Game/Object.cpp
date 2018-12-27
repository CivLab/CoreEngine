#include "Object.h"

Object::Object()
{
}

Object::Object(std::string name, sf::Shape & shape, MovingElement movingElement)
{
	m_name = name;
	m_shape = &shape;
	m_Character = new Character(name);
}


Object::~Object()
{
}
