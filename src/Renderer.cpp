#include "Renderer.hpp"

namespace a_star {

Renderer::Renderer(Grid::SharedPtr pGrid, float nodeSize)
    : m_pGrid(pGrid)
    , m_nodeSize(nodeSize)
{
}

void Renderer::init()
{
    auto uNodeSize = static_cast<uint32_t>(m_nodeSize);
    uint32_t gridWidth = m_pGrid->getWidth();
    uint32_t gridHeight = m_pGrid->getHeight();
    uint32_t windowWidth = gridWidth * uNodeSize;
    uint32_t windowHeight = gridHeight * uNodeSize;

    m_pRenderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "A* Algorithm", sf::Style::Close);

    m_rects.reserve(gridWidth * gridHeight);
    for(uint32_t y = 0; y < m_pGrid->getHeight(); ++y)
    {
        auto fY = static_cast<float>(y);

        for(uint32_t x = 0; x < m_pGrid->getWidth(); ++x)
        {
            auto fX = static_cast<float>(x);
            m_rects.emplace_back(sf::Vector2f(m_nodeSize - 2, m_nodeSize - 2));
            m_rects.back().setPosition(fX * m_nodeSize + 1, fY * m_nodeSize + 1);
            m_rects.back().setOutlineColor(sf::Color::Black);
            m_rects.back().setOutlineThickness(1);
        }
    }
}

void Renderer::update()
{
    sf::Event ev;
    while(m_pRenderWindow->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed)
            m_pRenderWindow->close();
    }
}

void Renderer::render()
{
    m_pRenderWindow->clear(sf::Color::Black);

    uint32_t gridWidth = m_pGrid->getWidth();
    uint32_t gridHeight = m_pGrid->getHeight();
    for(uint32_t y = 0; y < gridHeight; ++y)
    {
        for(uint32_t x = 0; x < gridWidth; ++x)
        {
            auto& rect = getRect(x, y);

            auto node = m_pGrid->getNode(x, y);
            if(node->isWalkable())
                rect.setFillColor(sf::Color::White);
            else
                rect.setFillColor(sf::Color::Black);

            m_pRenderWindow->draw(rect);
        }
    }

    m_pRenderWindow->display();
}

bool Renderer::isOpen() const
{
    if(m_pRenderWindow)
        return m_pRenderWindow->isOpen();
    
    return false;
}

sf::RectangleShape& Renderer::getRect(uint32_t x, uint32_t y)
{
    return m_rects.at(y * m_pGrid->getWidth() + x);
}

}