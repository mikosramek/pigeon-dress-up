#include "MouseHelper.h"
#include <iostream>

MouseHelper::MouseHelper() {
	m_mousePosition = sf::Vector2i(0, 0);
	m_font.loadFromFile("assets/fonts/comic.ttf");
	m_isPressed = false;
	m_isClicked = false;
	m_isDoubleClicked = false;
	m_framesSinceClick = 0;
	m_doubleClickBuffer = 24;
}

MouseHelper::~MouseHelper() {}
void MouseHelper::Tick(sf::RenderWindow& l_window) {
	m_mousePosition = sf::Mouse::getPosition(l_window);
	m_isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (m_framesSinceClick < m_doubleClickBuffer) {
		m_framesSinceClick += 1;
	}
	if (m_framesSinceClick > 5) {
		m_isClicked = false;
	}
	if (m_framesSinceClick > m_doubleClickBuffer) {
		m_isDoubleClicked = false;
	}
}

void MouseHelper::HandleEvents(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (m_framesSinceClick < m_doubleClickBuffer) {
				m_isDoubleClicked = true;
				m_framesSinceClick = m_doubleClickBuffer + 1;
			}
			else {
				m_isClicked = true;
				m_framesSinceClick = 0;
			}
		}
	}
}

sf::Vector2i MouseHelper::GetPosition() {
	return m_mousePosition;
}

bool MouseHelper::GetIsPressed() {
	return m_isPressed;
}

bool MouseHelper::GetIsClicked() {
	return m_isClicked;
}

bool MouseHelper::GetIsDoubledClicked() {
	return m_isDoubleClicked;
}

void MouseHelper::Render(sf::RenderWindow& l_window) {

	sf::Text text = sf::Text(
		"x: " + std::to_string(m_mousePosition.x) +
		" y: " + std::to_string(m_mousePosition.y) +
		" pressed: " + (m_isPressed ? "yes" : "no") +
		" clicked: " + (m_isClicked ? "yes" : "no") +
		" d clicked: " + (m_isDoubleClicked ? "yes" : "no"),
		m_font);
	text.setFillColor(sf::Color::Black);
	l_window.draw(text);
}