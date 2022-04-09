#pragma once
#include <SFML/Graphics.hpp>
#include "MouseHelper.h"

class MovableItem
{
public:
	MovableItem(sf::Vector2i startingPosition, int width, int height, sf::Color color);
	MovableItem();
	~MovableItem();
	void Render(sf::RenderWindow& l_window);
	void Tick(MouseHelper mouse);
private:
	bool m_isHeld;
	sf::Vector2i m_mouseOffset;
	sf::RectangleShape m_shape;
	sf::Vector2i m_position;
	sf::Vector2i m_size;
};

