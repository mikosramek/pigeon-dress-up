#pragma once
#include "Window.h"

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

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

