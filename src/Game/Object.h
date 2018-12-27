#pragma once
#include "..\WorldInterface\IObject.h"
#include <SFML/Graphics.hpp>
#include "../CoreStructure/MovingElement.h"
#include "../CoreCharacter/Character.h"

class Object : IObject
{
public:
	Object();
	Object(std::string name, sf::Shape& shape, MovingElement movingElement);
	virtual ~Object();

private:
	sf::Shape* m_shape;
	MovingElement* m_movingElement;
	Character* m_Character;
};

