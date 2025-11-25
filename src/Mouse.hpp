#ifndef A_STAR_MOUSE_HPP_
#define A_STAR_MOUSE_HPP_

#include <array>
#include <SFML/Window.hpp>

namespace a_star {

class Mouse
{
public:
    enum Keys
    {
        LEFT = 0,
        MIDDLE,
        RIGHT,
        NUM_KEYS
    };

private:
    uint8_t m_keyStates;
    uint8_t m_keyStatesLastFrame;
    std::array<int, 2> m_lastClickPosition;
    std::array<int, 2> m_position;

    void keyPressed(Keys key);
    void keyReleased(Keys key);

public:
    Mouse();

    void handleEvents(sf::Event& ev);
    void update();
    bool isKeyPressed(Keys key);
    bool isKeyReleased(Keys key);

    const std::array<int, 2>& getLastClickPosition() const;
    const std::array<int, 2>& getPosition() const;
};

}

#endif