#include "MovableItem.h"


MovableItem::MovableItem(sf::Vector2i startingPosition, int width, int height, sf::Color color) {
	m_mouseOffset = sf::Vector2i(0, 0);
	m_position = startingPosition;
	m_size = sf::Vector2i(width, height);
	m_isHeld = false;
	m_shape.setSize(sf::Vector2f(width, height));
	m_shape.setPosition(m_position.x - m_size.x / 2, m_position.y - m_size.y / 2);
	m_shape.setFillColor(color);
}

MovableItem::MovableItem() {
	m_mouseOffset = sf::Vector2i(0, 0);
	m_position = sf::Vector2i(-10, -10);
	m_size = sf::Vector2i(0, 0);
	m_isHeld = false;
	m_shape.setSize(sf::Vector2f(0, 0));
	m_shape.setPosition(m_position.x - m_size.x / 2, m_position.y - m_size.y / 2);
	m_shape.setFillColor(sf::Color::Yellow);
}

MovableItem::~MovableItem(){ }

void MovableItem::Tick(MouseHelper mouse) {
	// moving logic
	if (mouse.GetIsClicked() && !m_isHeld) {
		sf::Vector2i pos = mouse.GetPosition();
		if (pos.x < m_position.x + m_size.x / 2 &&
			pos.x > m_position.x - m_size.x / 2 &&
			pos.y < m_position.y + m_size.y / 2 &&
			pos.y > m_position.y - m_size.y / 2
			) {
			m_isHeld = true;
			m_mouseOffset = sf::Vector2i(m_position.x - pos.x, m_position.y - pos.y);
		}
	}
	else if (!mouse.GetIsPressed()) {
		m_isHeld = false;
	}
	if (m_isHeld) {
		sf::Vector2i pos = mouse.GetPosition();
		m_position = sf::Vector2i(pos.x + m_mouseOffset.x, pos.y + m_mouseOffset.y);
		m_shape.setPosition(m_position.x - m_size.x / 2, m_position.y - m_size.y / 2);
	}
}

void MovableItem::Render(sf::RenderWindow& l_window) {
	l_window.draw(m_shape);
}
