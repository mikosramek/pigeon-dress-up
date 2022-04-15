#include "Game.h"

Game::Game(uint16_t xSize):
    m_window("Pigeon Dress Up", sf::Vector2u(800, 600)),
    m_mouseHelper(),
    m_dataReader("assets/data/wardrobe.csv"),
    m_settings()
{
    m_elapsed = 0.0f;
    m_clock.restart();

    if (!m_clothing.loadFromFile("assets/images/clothing.png")) {
        // error
    }

    m_wardrobe.clear();

    Lines dataLines = m_dataReader.GetLines();
    std::string delimiter = ",";
    float lineValues[5] = {0,0,0,0,0};
    int lineValueIndex = 0;
    size_t pos = 0;
    for (int index = 0; index < dataLines.size(); index += 1) {
        std::string line = dataLines[index];
        lineValueIndex = 0;
        pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            lineValues[lineValueIndex++] = std::stof(token);
            line.erase(0, pos + delimiter.length());
        }
        lineValues[lineValueIndex++] = std::stof(line);
        
        m_wardrobe.push_back(
            MovableItem(
                sf::Vector2i(100, 100 + 100 * index),
                lineValues[0],
                lineValues[1],
                lineValues[2],
                lineValues[3],
                lineValues[4],
                &m_clothing,
                m_settings.GetIsDebug()
            )
        );
    }

    if (!m_mashaTexture.loadFromFile("assets/images/masha.jpg")) {
        // error
    }
    m_mashaTexture.setSmooth(true);
    m_masha.setTexture(m_mashaTexture);
    m_masha.setScale(0.25f, 0.25f);
    m_masha.setPosition(325, 50);
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

    m_window.Draw(m_masha);

    if (m_settings.GetIsDebug()) {
        m_mouseHelper.Render(*m_window.GetRenderWindow());
    }

    for (int i = 0; i < m_wardrobe.size(); i += 1) {
        m_wardrobe[i].Render(*m_window.GetRenderWindow());
    }


    m_window.EndDraw();
}