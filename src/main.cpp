#include <iostream>
#include <SFML/Graphics.hpp>
#include <boost/program_options.hpp>

#include "ProgramOptions.hpp"

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

    a_star::ProgramOptions programOptions(configFile);
    sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "A*", sf::Style::Close);

    while(renderWindow.isOpen())
    {
        sf::Event ev;
        while(renderWindow.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
                renderWindow.close();
        }

        renderWindow.clear(sf::Color::Black);
        renderWindow.display();
    }

    return 0;
}