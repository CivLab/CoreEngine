#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
private:
	void ProcessEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow myWindow;
	sf::CircleShape myPlayer;
	bool movingLeft, movingUp, movingRight, movingDown;
	float moveSpeedRatio;
};

Game::Game() : myWindow(sf::VideoMode(640, 480), "SFML Game"), myPlayer()
{
	myPlayer.setRadius(40.f);
	myPlayer.setFillColor(sf::Color::Red);
	myPlayer.setPosition(100.f, 100.f);
	moveSpeedRatio = 0.1;

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
		update();
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
	if (key == sf::Keyboard::Z) movingUp = isPressed;
	else if (key == sf::Keyboard::S) movingDown = isPressed;
	else if (key == sf::Keyboard::Q) movingLeft = isPressed;
	else if (key == sf::Keyboard::D) movingRight = isPressed;
}

void Game::update()
{
	sf::Vector2f movement(0.f, 0.f);
	if (movingUp) movement.y -= 1.f*moveSpeedRatio;
	if (movingDown) movement.y += 1.f*moveSpeedRatio;
	if (movingLeft) movement.x -= 1.f*moveSpeedRatio;
	if (movingRight) movement.x += 1.f*moveSpeedRatio;

	myPlayer.move(movement);
}

void Game::render()
{
	myWindow.clear();
	myWindow.draw(myPlayer);
	myWindow.display();
}

int main()
{
	Game game;
	game.run();

	return 0;
}