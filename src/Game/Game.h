#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

#define KEYUP sf::Keyboard::Z
#define KEYDOWN sf::Keyboard::S
#define KEYLEFT sf::Keyboard::Q
#define KEYRIGHT sf::Keyboard::D

class Game
{
public:
	Game();
	void run();
private:
	void ProcessEvents();
	void updatePlayerMovement();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow myWindow;
	sf::CircleShape myPlayer;
	World m_world;

	bool movingLeft, movingUp, movingRight, movingDown;
	float moveSpeedRatio;
};

