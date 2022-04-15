#pragma once
#include <SFML/Graphics.hpp>


class MouseHelper
{
public:
	MouseHelper();
	~MouseHelper();

	void Tick(sf::RenderWindow& l_window);
	void Render(sf::RenderWindow& l_window);
	sf::Vector2i GetPosition();
	bool GetIsPressed();
	bool GetIsClicked();
	bool GetIsDoubledClicked();
	void HandleEvents(sf::Event& event);
private:
	sf::Vector2i m_mousePosition;
	sf::Font m_font;

	bool m_isPressed;
	bool m_isClicked;
	bool m_isDoubleClicked;

	int m_doubleClickBuffer;

	int m_framesSinceClick;
};

