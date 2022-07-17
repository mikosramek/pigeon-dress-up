#include "Background.h"

Background::Background(std::string l_assetPath, int l_backgroundCount, int l_x, int l_y, int l_horizontalSize) {
    if (!m_texture.loadFromFile(l_assetPath)) { /*error*/ }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(l_x, l_y);

    m_index = 0;
    m_max_index = l_backgroundCount;
    m_horizontalSize = l_horizontalSize;

    UpdateSpriteRect();
}
Background::Background() {
    if (!m_texture.loadFromFile("assets/images/bgs.jpg")) { /*error*/ }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(0, 0);

    m_horizontalSize = m_texture.getSize().x;

    m_index = 0;
    m_max_index = 0;
    UpdateSpriteRect();
}

Background::~Background() { }

void Background::MoveBackgroundIndex(int direction) {
    m_index += direction;
    if (m_index < 0) {
        m_index = m_max_index - 1;
    }
    else if (m_index >= m_max_index) {
        m_index = 0;
    }
    UpdateSpriteRect();
}

void Background::UpdateSpriteRect() {
    m_sprite.setTextureRect(sf::IntRect(m_horizontalSize * m_index, 0, m_texture.getSize().x / m_max_index, m_texture.getSize().y));
}

void Background::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_sprite);
}

void Background::HandleEvents(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::F1) {
            MoveBackgroundIndex(-1);
        }
        else if (event.key.code == sf::Keyboard::F2) {
            MoveBackgroundIndex(1);
        }
    }
}
