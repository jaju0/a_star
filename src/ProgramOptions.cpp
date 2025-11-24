#include "ProgramOptions.hpp"

namespace a_star {

ProgramOptions::ProgramOptions()
    : m_description("grid")
    , m_nodeSize(0)
    , m_stepTime(0)
    , m_useDiagonalNeighbours(false)
    , m_distanceFunction("euclidean")
    , m_gridObstacleNodeColor(0x000000ff)
    , m_gridEmptyNodeColor(0xffffffff)
    , m_gridStartNodeColor(0x0000ffff)
    , m_gridTargetNodeColor(0xff00ffff)
    , m_gridOpenNodeColor(0x00ff00ff)
    , m_gridClosedNodeColor(0xff0000ff)
    , m_gridPathNodeColor(0x707070ff)
    , m_gridOutlineColor(0x000000ff)
    , m_gridOutlineThickness(1)
    , m_pathToGridFile("")
    , m_imageObstacleNodeColor(0x000000ff)
    , m_imageEmptyNodeColor(0xffffffff)
    , m_imageStartNodeColor(0xff0000ff)
    , m_imageTargetNodeColor(0x00ff00ff)
{
    m_description.add_options()
        ("grid.node_size", boost::program_options::value<uint32_t>()->default_value(10), "node size in pixels")
        ("grid.step_time", boost::program_options::value<uint32_t>()->default_value(5), "step time for each step of the algorithm")
        ("grid.use_diagonal_neighbours", boost::program_options::value<bool>()->default_value(false), "boolean whether diagonal neighbours will be used")
        ("grid.distance_function", boost::program_options::value<std::string>()->default_value("euclidean"), "distance function")
        ("grid.obstacle_node_color", boost::program_options::value<std::string>()->default_value("0x000000"), "obstacle node color for grid rendering")
        ("grid.empty_node_color", boost::program_options::value<std::string>()->default_value("0xffffff"), "empty node color for grid rendering")
        ("grid.start_node_color", boost::program_options::value<std::string>()->default_value("0x0000ff"), "start node color for grid rendering")
        ("grid.target_node_color", boost::program_options::value<std::string>()->default_value("0xff00ff"), "target node color for grid rendering")
        ("grid.open_node_color", boost::program_options::value<std::string>()->default_value("0x00ff00"), "open node color for grid rendering")
        ("grid.closed_node_color", boost::program_options::value<std::string>()->default_value("0xff0000"), "closed node color for grid rendering")
        ("grid.path_node_color", boost::program_options::value<std::string>()->default_value("0x707070"), "path node color for grid rendering")
        ("grid.outline_color", boost::program_options::value<std::string>()->default_value("0x000000"), "outline color for grid rendering")
        ("grid.outline_thickness", boost::program_options::value<uint32_t>()->default_value(1), "outline thickness for grid rendering")
        ("image.filepath", boost::program_options::value<std::string>()->default_value("grids/maze.png"), "path to grid file")
        ("image.obstacle_node_color", boost::program_options::value<std::string>()->default_value("0x000000"), "obstacle node color for image processing")
        ("image.empty_node_color", boost::program_options::value<std::string>()->default_value("0xffffff"), "empty node color for image processing")
        ("image.start_node_color", boost::program_options::value<std::string>()->default_value("0xff0000"), "start node color for image processing")
        ("image.target_node_color", boost::program_options::value<std::string>()->default_value("0x00ff00"), "target node color for image processing")
    ;
}

ProgramOptions& ProgramOptions::getInst()
{
    static ProgramOptions instance;
    return instance;
}

void ProgramOptions::loadFromConfigFile(const std::string& path)
{
    boost::program_options::store(boost::program_options::parse_config_file(path.c_str(), m_description), m_varmap);
    boost::program_options::notify(m_varmap);

    auto getColorFromVarmap = [this](const std::string& varname) {
        return static_cast<uint32_t>(std::stoi(m_varmap.at(varname).as<std::string>(), nullptr, 16)) << 8 ^ 0x000000ff;
    };

    m_nodeSize = m_varmap.at("grid.node_size").as<uint32_t>();
    m_stepTime = m_varmap.at("grid.step_time").as<uint32_t>();
    m_useDiagonalNeighbours = m_varmap.at("grid.use_diagonal_neighbours").as<bool>();
    m_distanceFunction = m_varmap.at("grid.distance_function").as<std::string>();
    m_gridObstacleNodeColor = getColorFromVarmap("grid.obstacle_node_color");
    m_gridEmptyNodeColor = getColorFromVarmap("grid.empty_node_color");
    m_gridStartNodeColor = getColorFromVarmap("grid.start_node_color");
    m_gridTargetNodeColor = getColorFromVarmap("grid.target_node_color");
    m_gridOpenNodeColor = getColorFromVarmap("grid.open_node_color");
    m_gridClosedNodeColor = getColorFromVarmap("grid.closed_node_color");
    m_gridPathNodeColor = getColorFromVarmap("grid.path_node_color");
    m_gridOutlineColor = getColorFromVarmap("grid.outline_color");
    m_gridOutlineThickness = m_varmap.at("grid.outline_thickness").as<uint32_t>();
    m_pathToGridFile = m_varmap.at("image.filepath").as<std::string>();
    m_imageObstacleNodeColor = getColorFromVarmap("image.obstacle_node_color");
    m_imageEmptyNodeColor = getColorFromVarmap("image.empty_node_color");
    m_imageStartNodeColor = getColorFromVarmap("image.start_node_color");
    m_imageTargetNodeColor = getColorFromVarmap("image.target_node_color");
}

uint32_t ProgramOptions::getNodeSize()
{
    return m_nodeSize;
}

uint32_t ProgramOptions::getStepTime()
{
    return m_stepTime;
}

bool ProgramOptions::diagonalNeighboursUsed()
{
    return m_useDiagonalNeighbours;
}

const std::string& ProgramOptions::getDistanceFunction()
{
    return m_distanceFunction;
}

uint32_t ProgramOptions::getGridObstacleNodeColor()
{
    return m_gridObstacleNodeColor;
}

uint32_t ProgramOptions::getGridEmptyNodeColor()
{
    return m_gridEmptyNodeColor;
}

uint32_t ProgramOptions::getGridStartNodeColor()
{
    return m_gridStartNodeColor;
}

uint32_t ProgramOptions::getGridTargetNodeColor()
{
    return m_gridTargetNodeColor;
}

uint32_t ProgramOptions::getGridOpenNodeColor()
{
    return m_gridOpenNodeColor;
}

uint32_t ProgramOptions::getGridClosedNodeColor()
{
    return m_gridClosedNodeColor;
}

uint32_t ProgramOptions::getGridPathNodeColor()
{
    return m_gridPathNodeColor;
}

uint32_t ProgramOptions::getGridOutlineColor()
{
    return m_gridOutlineColor;
}

uint32_t ProgramOptions::getGridOutlineThickness()
{
    return m_gridOutlineThickness;
}

const std::string& ProgramOptions::getPathToGridFile()
{
    return m_pathToGridFile;
}

uint32_t ProgramOptions::getImageObstacleNodeColor()
{
    return m_imageObstacleNodeColor;
}

uint32_t ProgramOptions::getImageEmptyNodeColor()
{
    return m_imageEmptyNodeColor;
}

uint32_t ProgramOptions::getImageStartNodeColor()
{
    return m_imageStartNodeColor;
}

uint32_t ProgramOptions::getImageTargetNodeColor()
{
    return m_imageTargetNodeColor;
}


}