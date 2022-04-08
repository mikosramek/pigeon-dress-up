#include "Game.h"

Game::Game(uint16_t xSize): m_window("Pigeon Dress Up", sf::Vector2u(800, 600)), m_mouseHelper() {
    //
    float fElapsed = m_elapsed.asSeconds();
    // m_mouseDebug = MouseDebug();
    m_plhoPosition.x = 200;
    m_plhoPosition.y = 200;
    m_plhoShape.setSize(sf::Vector2f(m_plhoSize, m_plhoSize));
    m_plhoShape.setPosition(m_plhoPosition.x - m_plhoSize / 2, m_plhoPosition.y - m_plhoSize / 2);
    m_plhoIsHeld = false;
    m_plhoOffset = sf::Vector2i(0, 0);
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update() {
	m_window.Update();

    // advance clock
    // if clock is above a certain amount of time
    // update game objects + reset clock
    
    // mouse helper.Tick(with array of clothing items)

    
    m_mouseHelper.Tick(*m_window.GetRenderWindow());
    // grab mouse coords
    // if mouse is pressed this frame
    // move that object to where the mouse is
    //if (m_mouseHelper.GetIsPressed()) {
    //    sf::Vector2i pos = m_mouseHelper.GetPosition();
    //    m_plhoPosition = sf::Vector2i(pos.x - m_plhoSize / 2, pos.y - m_plhoSize / 2);
    //}

    // grab mouse coords
    // check if mouse is pressed down (not held)
    // add item to currently held items
    // update position to mouse
    if (m_mouseHelper.GetIsPressed() && !m_plhoIsHeld) {
        sf::Vector2i pos = m_mouseHelper.GetPosition();
        // check for position
        //aabb check

        if (pos.x < m_plhoPosition.x + m_plhoSize / 2 &&
            pos.x > m_plhoPosition.x - m_plhoSize / 2 &&
            pos.y < m_plhoPosition.y + m_plhoSize / 2 &&
            pos.y > m_plhoPosition.y - m_plhoSize / 2
        ) {
            m_plhoIsHeld = true;
            m_plhoOffset = sf::Vector2i(m_plhoPosition.x - pos.x, m_plhoPosition.y - pos.y);
        }
    }
    else if (!m_mouseHelper.GetIsPressed()) {
        m_plhoIsHeld = false;
    }

    if (m_plhoIsHeld) {
        sf::Vector2i pos = m_mouseHelper.GetPosition();
        m_plhoPosition = sf::Vector2i(pos.x + m_plhoOffset.x, pos.y + m_plhoOffset.y);
        m_plhoShape.setPosition(m_plhoPosition.x - m_plhoSize / 2, m_plhoPosition.y - m_plhoSize / 2);
    }

    // grab mouse coords
    // check if mouse is pressed down (not held)
    // add item to currently held items + record offset
    // update position to mouse w/ offset
}

Window* Game::GetWindow() {
    return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::Render() {
    m_window.BeginDraw();
    m_mouseHelper.Render(*m_window.GetRenderWindow());

    // item.Render
    m_plhoShape.setFillColor(sf::Color::Red);
    m_window.Draw(m_plhoShape);

    m_window.EndDraw();
}
