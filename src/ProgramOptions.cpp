#include "ProgramOptions.hpp"
#include <SFML/Graphics.hpp>

namespace a_star {

ProgramOptions::ProgramOptions(const std::string& configFile)
    : m_description("grid")
    , m_pathToGridFile("")
    , m_nodeSize(0)
{
    m_description.add_options()
        ("grid.filepath", boost::program_options::value<std::string>()->default_value("grids/maze.png"), "path to grid file")
        ("grid.node_size", boost::program_options::value<uint32_t>()->default_value(10), "node size in pixels")
    ;

    boost::program_options::store(boost::program_options::parse_config_file(configFile.c_str(), m_description), m_varmap);
    boost::program_options::notify(m_varmap);

    m_pathToGridFile = m_varmap.at("grid.filepath").as<std::string>();
    m_nodeSize = m_varmap.at("grid.node_size").as<uint32_t>();
}

const std::string& ProgramOptions::getPathToGridFile()
{
    return m_pathToGridFile;
}

uint32_t ProgramOptions::getNodeSize()
{
    return m_nodeSize;
}

}