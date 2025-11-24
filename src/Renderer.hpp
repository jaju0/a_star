#ifndef A_STAR_RENDERER_HPP_
#define A_STAR_RENDERER_HPP_

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Grid.hpp"

namespace a_star {

class Renderer
{
public:
    using SharedPtr = std::shared_ptr<Renderer>;

private:
    Grid::SharedPtr m_pGrid;
    std::shared_ptr<sf::RenderWindow> m_pRenderWindow;
    std::vector<sf::RectangleShape> m_rects;

    sf::Color m_obstacleNodeColor;
    sf::Color m_emptyNodeColor;
    sf::Color m_startNodeColor;
    sf::Color m_targetNodeColor;
    sf::Color m_openNodeColor;
    sf::Color m_closedNodeColor;
    sf::Color m_pathNodeColor;

    sf::Color m_outlineColor;
    uint32_t m_outlineThickness;

    sf::RectangleShape& getRect(uint32_t x, uint32_t y);

public:
    Renderer(Grid::SharedPtr pGrid);
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void init();
    void update();
    void render();

    bool isOpen() const;
};

}

#endif