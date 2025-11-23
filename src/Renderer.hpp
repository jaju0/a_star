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

    float m_nodeSize;
    std::vector<sf::RectangleShape> m_rects;

    sf::RectangleShape& getRect(uint32_t x, uint32_t y);

public:
    Renderer(Grid::SharedPtr pGrid, float nodeSize);
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void init();
    void update();
    void render();

    bool isOpen() const;
};

}

#endif