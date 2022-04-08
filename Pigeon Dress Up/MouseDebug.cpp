#include "MouseDebug.h"

MouseDebug::MouseDebug() {
	m_mousePosition = sf::Vector2i(0, 0);
	m_font.loadFromFile("assets/fonts/comic.ttf");
}

MouseDebug::~MouseDebug() {}

void MouseDebug::Render(sf::RenderWindow& l_window) {
	m_mousePosition = sf::Mouse::getPosition(l_window);

	sf::Text text = sf::Text("x: " + std::to_string(m_mousePosition.x) + " y: " + std::to_string(m_mousePosition.y), m_font);
	l_window.draw(text);
}