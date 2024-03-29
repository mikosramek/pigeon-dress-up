#pragma once
#include "Window.h"
#include "MouseHelper.h"
#include "MovableItem.h"
#include "DataReader.h"
#include "GlobalSettings.h"
#include "Background.h"

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

	DataReader m_dataReader;
	Wardrobe m_wardrobe;

	sf::Sprite m_masha;
	sf::Texture m_mashaTexture;
	sf::Texture m_clothing;
	sf::Texture m_foregroundTexture;
	sf::Sprite m_foreground;

	GlobalSettings m_settings;
	Background m_background;
};

