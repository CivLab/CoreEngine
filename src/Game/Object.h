#pragma once
#include "..\WorldInterface\IObject.h"
#include <SFML/Graphics.hpp>
#include "../CoreStructure/MovingElement.h"
#include "../CoreCharacter/Character.h"

class Object : IObject
{
public:	

	enum direction
	{
		UP = 0,
		RIGHT = 1,
		DOWN = 2,
		LEFT = 3
	};

	Object();
	Object(std::string name, sf::CircleShape& shape, MovingElement movingElement);
	virtual ~Object();

	void setTexture(const char * file);

	void move(sf::Vector2f);
	void moveInGame(Object::direction, float factor = 1.f);
	void rotate(float angle);

//private:
	sf::CircleShape* m_shape;
	sf::Texture m_texture;
	MovingElement* m_movingElement;
	Character* m_Character;



	// Inherited via IObject
	virtual IElement * getElement() override;

};

