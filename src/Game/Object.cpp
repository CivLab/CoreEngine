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

void Object::move(sf::Vector2f vector)
{
	m_shape->move(vector);
	m_movingElement->updatePosition(Point(vector.x, vector.y));
}

void Object::moveInGame(Object::direction myDirection, float factor)
{
	Point myPoint = m_movingElement->getDirection();
	myPoint = myPoint.operator*(factor);
	myPoint.rotate(myDirection * 90.f);

	sf::Vector2f myVector((float)myPoint.X, (float)myPoint.Y);
	move(myVector);
}
