#include "App.hpp"
#include "EuclideanDistance.hpp"
#include "ManhattanDistance.hpp"

namespace a_star {

App::App(ProgramOptions& programOptions)
    : m_programOptions(programOptions)
{
}

void App::start()
{
    init();
    loop();
}

void App::loop()
{
    while(m_pRenderer->isOpen())
    {
        update();
        m_pRenderer->render();
    }
}

void App::init()
{
    float fNodeSize = static_cast<float>(m_programOptions.getNodeSize());

    m_pGrid = Grid::loadFromImageFile(m_programOptions.getPathToGridFile());
    m_pAStar = std::make_shared<AStar>(m_pGrid, std::make_shared<ManhattanDistance>());
    m_pRenderer = std::make_shared<Renderer>(m_pGrid, fNodeSize);

    m_pAStar->init();
    m_pRenderer->init();
}

void App::update()
{
    m_pRenderer->update();
    m_pAStar->update();
}

}