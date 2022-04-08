#include "MouseHelper.h"

MouseHelper::MouseHelper() {
	m_mousePosition = sf::Vector2i(0, 0);
	m_font.loadFromFile("assets/fonts/comic.ttf");
	m_isPressed = false;
}

MouseHelper::~MouseHelper() {}
void MouseHelper::Tick(sf::RenderWindow& l_window) {
	m_mousePosition = sf::Mouse::getPosition(l_window);
	m_isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2i MouseHelper::GetPosition() {
	return m_mousePosition;
}

bool MouseHelper::GetIsPressed() {
	return m_isPressed;
}

void MouseHelper::Render(sf::RenderWindow& l_window) {

	sf::Text text = sf::Text(
		"x: " + std::to_string(m_mousePosition.x) +
		" y: " + std::to_string(m_mousePosition.y) +
		" pressed: " + (m_isPressed ? "yes" : "no"),
		m_font);
	l_window.draw(text);
}