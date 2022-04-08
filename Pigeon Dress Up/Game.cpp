#include "Game.h"

Game::Game(uint16_t xSize): m_window("Pigeon Dress Up", sf::Vector2u(800, 600)), m_mouseDebug() {
    //
    float fElapsed = m_elapsed.asSeconds();
    // m_mouseDebug = MouseDebug();
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update() {
	m_window.Update();
}

Window* Game::GetWindow() {
    return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::Render() {
    m_window.BeginDraw();
    m_mouseDebug.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}
