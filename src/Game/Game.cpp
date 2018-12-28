#include "Game.h"

Game::Game() : myWindow(sf::VideoMode(640, 480), "SFML Game"), myPlayer()
{
	m_player = new Object();
	/*
	myPlayer.setRadius(40.f);
	myPlayer.setOrigin(40., 40.);

	myPlayer.setPosition(100.f, 100.f);
	moveSpeedRatio = 0.05f;
	turnSpeedRatio = 0.025f;

	if (!m_texture.loadFromFile("../ressources/greenChar40px.jpg"))
	{
		myPlayer.setFillColor(sf::Color::Red);
	}
	else
	{
		myPlayer.setTexture(&m_texture);
	}
	*/
	initializePlayer();

	movingDown = false;
	movingLeft = false;
	movingRight = false;
	movingUp = false;
	turningLeft = false;
	turningRight = false;
}

void Game::initializePlayer()
{
	m_player->m_shape->setRadius(40.f);
	m_player->m_shape->setOrigin(40., 40.);

	m_player->m_shape->setPosition(100.f, 100.f);
	moveSpeedRatio = 0.05f;
	turnSpeedRatio = 0.025f;

	m_player->setTexture("../ressources/greenChar40px.jpg");
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
	else if (key == KEYTURNLEFT) turningLeft = isPressed;
	else if (key == KEYTURNRIGHT) turningRight = isPressed;
}

/*
void Game::updatePlayerMovement()
{
	sf::Vector2f playerMovement(0.f, 0.f);
	if (movingUp) playerMovement.y -= 1.f*moveSpeedRatio;
	if (movingDown) playerMovement.y += 1.f*moveSpeedRatio;
	if (movingLeft) playerMovement.x -= 1.f*moveSpeedRatio;
	if (movingRight) playerMovement.x += 1.f*moveSpeedRatio;
	if (turningLeft) myPlayer.rotate(-turnSpeedRatio);
	if (turningRight) myPlayer.rotate(turnSpeedRatio);

	myPlayer.move(playerMovement);
}
*/
void Game::updatePlayerMovement()
{
	if (movingUp) m_player->moveInGame(Object::UP, moveSpeedRatio);
	if (movingDown) m_player->moveInGame(Object::DOWN, moveSpeedRatio);
	if (movingLeft) m_player->moveInGame(Object::LEFT, moveSpeedRatio);
	if (movingRight) m_player->moveInGame(Object::RIGHT, moveSpeedRatio);
	if (turningLeft) m_player->rotate(-turnSpeedRatio);
	if (turningRight) m_player->rotate(turnSpeedRatio);
}

void Game::render()
{
	myWindow.clear();
	myWindow.draw(*m_player->m_shape);
	myWindow.display();
}
