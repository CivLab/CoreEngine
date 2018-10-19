#include "Game.h"

Game::Game() : myWindow(sf::VideoMode(640, 480), "SFML Game"), myPlayer()
{
	myPlayer.setRadius(40.f);
	myPlayer.setFillColor(sf::Color::Red);
	myPlayer.setPosition(100.f, 100.f);
	moveSpeedRatio = 0.1f;

	movingDown = false;
	movingLeft = false;
	movingRight = false;
	movingUp = false;
}

void Game::run()
{
	while (myWindow.isOpen())
	{
		ProcessEvents();
		updatePlayerMovement();
		render();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (myWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed: handlePlayerInput(event.key.code, true); break;
		case sf::Event::KeyReleased: handlePlayerInput(event.key.code, false); break;
		case sf::Event::Closed: myWindow.close(); break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == KEYUP) movingUp = isPressed;
	else if (key == KEYDOWN) movingDown = isPressed;
	else if (key == KEYLEFT) movingLeft = isPressed;
	else if (key == KEYRIGHT) movingRight = isPressed;
}

void Game::updatePlayerMovement()
{
	sf::Vector2f playerMovement(0.f, 0.f);
	if (movingUp) playerMovement.y -= 1.f*moveSpeedRatio;
	if (movingDown) playerMovement.y += 1.f*moveSpeedRatio;
	if (movingLeft) playerMovement.x -= 1.f*moveSpeedRatio;
	if (movingRight) playerMovement.x += 1.f*moveSpeedRatio;

	myPlayer.move(playerMovement);
}

void Game::render()
{
	myWindow.clear();
	myWindow.draw(myPlayer);
	myWindow.display();
}
