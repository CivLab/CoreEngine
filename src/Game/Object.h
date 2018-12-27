#pragma once
#include "..\WorldInterface\IObject.h"
#include <SFML/Graphics.hpp>
#include "../CoreStructure/MovingElement.h"
#include "../CoreCharacter/Character.h"

class Object : IObject
{
public:
	Object();
	Object(std::string name, sf::CircleShape& shape, MovingElement movingElement);
	virtual ~Object();

	void setTexture(const char * file);

//private:
	sf::CircleShape* m_shape;
	sf::Texture m_texture;
	MovingElement* m_movingElement;
	Character* m_Character;
};

