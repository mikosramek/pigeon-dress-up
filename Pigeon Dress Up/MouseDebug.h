#pragma once
#include <SFML/Graphics.hpp>


class MouseDebug
{
public:
	MouseDebug();
	~MouseDebug();

	void Render(sf::RenderWindow& l_window);
private:
	sf::Vector2i m_mousePosition;
	sf::Font m_font;
};

