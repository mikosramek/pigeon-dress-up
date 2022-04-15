#pragma once
#include <SFML/Graphics.hpp>
#include "MouseHelper.h"

class MovableItem
{
public:
	MovableItem(sf::Vector2i startingPosition, float x, float y, float width, float height, float scale, sf::Texture* l_texture, bool isDebug);
	MovableItem();
	~MovableItem();
	void Render(sf::RenderWindow& l_window);
	void Tick(MouseHelper mouse);
private:
	bool IsInShape(sf::Vector2i pos);

	bool m_isHeld;
	sf::Vector2i m_mouseOffset;
	sf::RectangleShape m_shape;
	sf::Vector2i m_position;

	float m_scale;
	sf::Vector2f m_size;
	sf::Vector2f m_spritePos;

	void FlipItem();
	bool m_isFlipped;

	bool m_isDebug;

	sf::Sprite m_sprite;
	sf::Texture* m_texture;
};

