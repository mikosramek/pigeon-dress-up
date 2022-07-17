#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background(std::string l_assetPath, int l_backgroundCount, int l_x, int l_y, int l_horizontalSize);
	Background();
	~Background();
	void Render(sf::RenderWindow& l_window);
	void MoveBackgroundIndex(int direction);
	void HandleEvents(sf::Event& event);
private:
	int m_index;
	int m_max_index;

	int m_horizontalSize;

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	void UpdateSpriteRect();
};

