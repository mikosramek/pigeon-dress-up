#include "MovableItem.h"
#include <iostream>

MovableItem::MovableItem(sf::Vector2i startingPosition, float x, float y, float width, float height, float scale, sf::Texture* l_texture, bool isDebug) {
	m_isHeld = false;
	m_isFlipped = false;
	m_size.x = width;
	m_size.y = height;

	m_isDebug = isDebug;

	m_spritePos.x = x;
	m_spritePos.y = y;

	m_scale = scale;
	m_position = startingPosition;
	m_mouseOffset = sf::Vector2i(0, 0);


	m_shape.setSize(sf::Vector2f(m_size.x * m_scale, m_size.y * m_scale));
	m_shape.setPosition(m_position.x - m_size.x * m_scale / 2, m_position.y - m_size.y * m_scale / 2);
	m_shape.setFillColor(sf::Color::White);
	m_shape.setOutlineColor(sf::Color::Yellow);
	m_shape.setOutlineThickness(2);
	

	m_texture = l_texture;
	m_sprite.setTexture((*m_texture));
	m_sprite.setScale(m_scale, m_scale);

	m_sprite.setPosition(m_position.x - m_size.x * m_scale / 2, m_position.y - m_size.y * m_scale / 2);
	
	m_sprite.setTextureRect(sf::IntRect(m_spritePos.x, m_spritePos.y, width, height));
}

MovableItem::MovableItem() {
	m_mouseOffset = sf::Vector2i(0, 0);
	m_position = sf::Vector2i(-10, -10);
	m_size = sf::Vector2f(0, 0);
	m_isHeld = false;
	m_isFlipped = false;
	m_shape.setSize(sf::Vector2f(0, 0));
	m_shape.setPosition(m_position.x - m_size.x / 2, m_position.y - m_size.y / 2);
	m_shape.setFillColor(sf::Color::Yellow);
	m_scale = 0;

	m_isDebug = false;

	m_texture->create(0.0f, 0.0f);
}

MovableItem::~MovableItem(){ }

bool MovableItem::IsInShape(sf::Vector2i pos) {
	return (
		pos.x < (m_position.x + (m_size.x * m_scale) / 2) &&
		pos.x > (m_position.x - m_size.x * m_scale / 2) &&
		pos.y < (m_position.y + (m_size.y * m_scale) / 2) &&
		pos.y > (m_position.y - m_size.y * m_scale / 2)
	);

	// TODO: add in smaller shape checking
}


void MovableItem::FlipItem() {
	m_isFlipped = !m_isFlipped;
	m_sprite.setTextureRect(sf::IntRect(
		m_spritePos.x + (m_isFlipped ? m_size.x : 0),
		m_spritePos.y,
		m_isFlipped ? -m_size.x : m_size.x,
		m_size.y
	));
}

void MovableItem::Tick(MouseHelper mouse) {
	// moving logic
	if (mouse.GetIsClicked() && !m_isHeld && IsInShape(mouse.GetPosition())) {
		m_isHeld = true;
		m_mouseOffset = sf::Vector2i(m_position.x - mouse.GetPosition().x, m_position.y - mouse.GetPosition().y);
	}
	else if (!mouse.GetIsPressed()) {
		m_isHeld = false;
	}
	if (mouse.GetIsDoubledClicked() && IsInShape(mouse.GetPosition())) {
		FlipItem();
	}
	if (m_isHeld) {
		sf::Vector2i pos = mouse.GetPosition();
		m_position = sf::Vector2i(pos.x + m_mouseOffset.x, pos.y + m_mouseOffset.y);
		m_shape.setPosition(m_position.x - m_size.x * m_scale / 2.0f, m_position.y - m_size.y * m_scale / 2.0f);
		m_sprite.setPosition(m_position.x - m_size.x * m_scale / 2.0f, m_position.y - m_size.y * m_scale / 2.0f);
	}
}

void MovableItem::Render(sf::RenderWindow& l_window) {
	if (m_isDebug) {
		l_window.draw(m_shape);
	}
	l_window.draw(m_sprite);
}
