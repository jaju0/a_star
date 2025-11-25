#include "Renderer.hpp"
#include "ProgramOptions.hpp"

namespace a_star {

Renderer::Renderer(Grid::SharedPtr pGrid)
    : m_pGrid(pGrid)
    , m_obstacleNodeColor(sf::Color::Black)
    , m_emptyNodeColor(sf::Color::White)
    , m_startNodeColor(sf::Color::Magenta)
    , m_targetNodeColor(sf::Color::Red)
    , m_openNodeColor(sf::Color::Green)
    , m_closedNodeColor(sf::Color::Red)
    , m_pathNodeColor(sf::Color(70, 70, 70))
    , m_outlineColor(sf::Color::Black)
    , m_outlineThickness(1)
{
}

void Renderer::init()
{
    auto& programOptions = ProgramOptions::getInst();

    m_obstacleNodeColor = sf::Color(programOptions.getGridObstacleNodeColor());
    m_emptyNodeColor = sf::Color(programOptions.getGridEmptyNodeColor());
    m_startNodeColor = sf::Color(programOptions.getGridStartNodeColor());
    m_targetNodeColor = sf::Color(programOptions.getGridTargetNodeColor());
    m_openNodeColor = sf::Color(programOptions.getGridOpenNodeColor());
    m_closedNodeColor = sf::Color(programOptions.getGridClosedNodeColor());
    m_pathNodeColor = sf::Color(programOptions.getGridPathNodeColor());
    m_outlineColor = sf::Color(programOptions.getGridOutlineColor());
    m_outlineThickness = programOptions.getGridOutlineThickness();

    uint32_t nodeSize = programOptions.getNodeSize();
    float fNodeSize = static_cast<float>(nodeSize);
    float fOutlineThickness = static_cast<float>(m_outlineThickness);
    uint32_t gridWidth = m_pGrid->getWidth();
    uint32_t gridHeight = m_pGrid->getHeight();
    uint32_t windowWidth = gridWidth * nodeSize;
    uint32_t windowHeight = gridHeight * nodeSize;

    m_pRenderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "A* Algorithm", sf::Style::Close);

    m_rects.reserve(gridWidth * gridHeight);
    for(uint32_t y = 0; y < m_pGrid->getHeight(); ++y)
    {
        auto fY = static_cast<float>(y);

        for(uint32_t x = 0; x < m_pGrid->getWidth(); ++x)
        {
            float fX = static_cast<float>(x);

            if(fOutlineThickness < fNodeSize / 2)
            {
                m_rects.emplace_back(sf::Vector2f(fNodeSize - fOutlineThickness * 2, fNodeSize - fOutlineThickness * 2));
                m_rects.back().setPosition(fX * fNodeSize + fOutlineThickness, fY * fNodeSize + fOutlineThickness);
                m_rects.back().setOutlineColor(m_outlineColor);
                m_rects.back().setOutlineThickness(m_outlineThickness);
                continue;
            }

            m_rects.emplace_back(sf::Vector2f(fNodeSize, fNodeSize));
            m_rects.back().setPosition(fX * fNodeSize, fY * fNodeSize);
            m_rects.back().setOutlineColor(m_outlineColor);
            m_rects.back().setOutlineThickness(0);
        }
    }
}

void Renderer::update(Keyboard& keyboard)
{
    sf::Event ev;
    while(m_pRenderWindow->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed)
            m_pRenderWindow->close();
        
        keyboard.handleEvents(ev);
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
            if(node->equalCoords(*m_pGrid->getStartNode()))
                rect.setFillColor(m_startNodeColor);
            else if(node->equalCoords(*m_pGrid->getTargetNode()))
                rect.setFillColor(m_targetNodeColor);
            else if(node->isPartOfPath())
                rect.setFillColor(m_pathNodeColor);
            else if(node->isClosed())
                rect.setFillColor(m_closedNodeColor);
            else if(node->isOpen())
                rect.setFillColor(m_openNodeColor);
            else if(node->isWalkable())
                rect.setFillColor(m_emptyNodeColor);
            else
                rect.setFillColor(m_obstacleNodeColor);

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