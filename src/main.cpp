#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
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