#include <iostream>
#include <boost/program_options.hpp>

#include "ProgramOptions.hpp"
#include "App.hpp"

int main(int argc, char** argv)
{
    boost::program_options::variables_map varmap;
    boost::program_options::options_description desc;

    desc.add_options()
        ("config", boost::program_options::value<std::string>()->default_value("config.ini"), "path to config file")
    ;

    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), varmap);
    boost::program_options::notify(varmap);

    std::string configFile = varmap.at("config").as<std::string>();
    a_star::ProgramOptions::getInst().loadFromConfigFile(configFile);

    a_star::App app;
    app.start();

    return 0;
}