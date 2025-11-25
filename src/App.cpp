#include "App.hpp"
#include "EuclideanDistance.hpp"
#include "ManhattanDistance.hpp"

namespace a_star {

App::App()
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
    auto& programOptions = ProgramOptions::getInst();

    HeuristicFunction::SharedPtr heuristicFunction;

    if(programOptions.getDistanceFunction() == "manhattan")
        heuristicFunction = std::make_shared<ManhattanDistance>();
    else
        heuristicFunction = std::make_shared<EuclideanDistance>();

    m_pGrid = Grid::loadFromImageFile(ProgramOptions::getInst().getPathToGridFile());
    m_pAStar = std::make_shared<AStar>(m_pGrid, heuristicFunction);
    m_pRenderer = std::make_shared<Renderer>(m_pGrid);

    m_pAStar->init();
    m_pRenderer->init();
}

void App::update()
{
    m_pRenderer->update(m_keyboard);

    if(m_keyboard.isKeyReleased(Keyboard::Q))
        m_pRenderer->close();
    if(m_keyboard.isKeyReleased(Keyboard::SPACE))
        m_pAStar->reset();
    if(m_keyboard.isKeyReleased(Keyboard::S))
        m_pAStar->stop();
    if(m_keyboard.isKeyReleased(Keyboard::R))
        m_pAStar->resume();

    m_pAStar->update();
}

}