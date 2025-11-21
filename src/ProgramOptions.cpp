#include "ProgramOptions.hpp"
#include <SFML/Graphics.hpp>

namespace a_star {

ProgramOptions::ProgramOptions(const std::string& configFile)
    : m_description("window")
    , m_windowWidth(0)
    , m_windowHeight(0)
    , m_fullscreen(false)
{
    m_description.add_options()
        ("window.width", boost::program_options::value<uint32_t>()->default_value(800), "window width")
        ("window.height", boost::program_options::value<uint32_t>()->default_value(600), "window height")
        ("window.fullscreen", boost::program_options::value<bool>()->default_value(false), "fullscreen")
    ;

    boost::program_options::store(boost::program_options::parse_config_file(configFile.c_str(), m_description), m_varmap);
    boost::program_options::notify(m_varmap);

    m_windowWidth = m_varmap.at("window.width").as<uint32_t>();
    m_windowHeight = m_varmap.at("window.height").as<uint32_t>();
    m_fullscreen = m_varmap.at("window.fullscreen").as<bool>();

    if(m_fullscreen)
    {
        auto desktopMode = sf::VideoMode::getDesktopMode();
        m_windowWidth = desktopMode.width;
        m_windowHeight = desktopMode.height;
    }
}

uint32_t ProgramOptions::getWindowWidth()
{
    return m_windowWidth;
}

uint32_t ProgramOptions::getWindowHeight()
{
    return m_windowHeight;
}

bool ProgramOptions::isFullscreen()
{
    return m_fullscreen;
}

}