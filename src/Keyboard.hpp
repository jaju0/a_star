#ifndef A_STAR_KEYBOARD_HPP_
#define A_STAR_KEYBOARD_HPP_

#include <cstdint>
#include <SFML/Window.hpp>

namespace a_star {

class Keyboard
{
public:
    enum Keys
    {
        SPACE = 0,
        Q,
        R,
        S,
        Y,
        X,
        C,
        NUM_KEYS
    };

private:
    uint32_t m_keyStates;
    uint32_t m_keyStatesLastFrame;

    void keyPressed(Keys key);
    void keyReleased(Keys key);

public:
    Keyboard();

    void handleEvents(sf::Event& ev);
    void update();
    bool isKeyPressed(Keys key);
    bool isKeyReleased(Keys key);
};

}

#endif