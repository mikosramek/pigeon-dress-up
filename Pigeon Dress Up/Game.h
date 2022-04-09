#pragma once
#include "Window.h"
#include "MouseHelper.h"
#include "MovableItem.h"

using Wardrobe = std::vector<MovableItem>;

class Game
{
public:
	Game(uint16_t xSize);
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	float GetElapsed();
	void RestartClock();
private:
	Window m_window;
	MouseHelper m_mouseHelper;

	sf::Clock m_clock;
	float m_elapsed;

	Wardrobe m_wardrobe;
};

