#pragma once
#include "Window.h"
#include "MouseHelper.h"

class Game
{
public:
	Game(uint16_t xSize);
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_window;
	MouseHelper m_mouseHelper;

	sf::Clock m_clock;
	sf::Time m_elapsed;

	bool m_plhoIsHeld;
	sf::Vector2i m_plhoOffset;
	sf::RectangleShape m_plhoShape;
	sf::Vector2i m_plhoPosition;
	int m_plhoSize = 50;
};

