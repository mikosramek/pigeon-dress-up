#include "Game.h"

Game::Game(uint16_t xSize):
    m_window("Pigeon Dress Up", sf::Vector2u(800, 600)),
    m_mouseHelper()
{
    m_elapsed = 0.0f;
    m_clock.restart();
    // m_items[0] = MovableItem(sf::Vector2i(100, 100), 50, 100);
    // m_items[1] = MovableItem(sf::Vector2i(200, 200), 40, 40);

    m_wardrobe.clear();
    m_wardrobe.push_back(MovableItem(sf::Vector2i(100, 100), 50, 100, sf::Color::Red));
    m_wardrobe.push_back(MovableItem(sf::Vector2i(175, 100), 25, 25, sf::Color::White));
    m_wardrobe.push_back(MovableItem(sf::Vector2i(300, 100), 150, 150, sf::Color::Yellow));
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update() {
	sf::Event event = m_window.Update();
    m_mouseHelper.HandleEvents(event);

    float timestep = 0.01f;

    if (m_elapsed >= timestep) {
        m_elapsed -= timestep;
        for (int i = 0; i < m_wardrobe.size(); i += 1) {
            m_wardrobe[i].Tick(m_mouseHelper);
        }
        m_mouseHelper.Tick(*m_window.GetRenderWindow());
    }
    
}

Window* Game::GetWindow() {
    return &m_window;
}

float Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }

void Game::Render() {
    m_window.BeginDraw();

    m_mouseHelper.Render(*m_window.GetRenderWindow());
    for (int i = 0; i < m_wardrobe.size(); i += 1) {
        m_wardrobe[i].Render(*m_window.GetRenderWindow());
    }

    m_window.EndDraw();
}