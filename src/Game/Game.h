#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Parameters.h"
#include "Object.h"

#define KEYUP sf::Keyboard::Z
#define KEYDOWN sf::Keyboard::S
#define KEYLEFT sf::Keyboard::Q
#define KEYRIGHT sf::Keyboard::D
#define KEYTURNLEFT sf::Keyboard::A
#define KEYTURNRIGHT sf::Keyboard::E


class Game
{
public:
	Game();
	void initializePlayer();
	void run();
private:
	void ProcessEvents();
	void updatePlayerMovement();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow myWindow;
	sf::CircleShape myPlayer;
	sf::Texture m_texture;
	World m_world;
	Object* m_player;

	bool movingLeft, movingUp, movingRight, movingDown, turningLeft, turningRight;
	float moveSpeedRatio, turnSpeedRatio;
};

