#include "Keyboard.hpp"


namespace a_star {

Keyboard::Keyboard()
    : m_keyStates(0)
    , m_keyStatesLastFrame(0)
{
}

void Keyboard::handleEvents(sf::Event& ev)
{
    m_keyStatesLastFrame = m_keyStates;

    if(ev.type == sf::Event::KeyPressed)
    {
        switch(ev.key.code)
        {
        case sf::Keyboard::Space: keyPressed(Keyboard::SPACE); break;
        case sf::Keyboard::Q: keyPressed(Keyboard::Q); break;
        case sf::Keyboard::R: keyPressed(Keyboard::R); break;
        case sf::Keyboard::S: keyPressed(Keyboard::S); break;
        default:
            break;
        }
    }
    else if(ev.type == sf::Event::KeyReleased)
    {
        switch(ev.key.code)
        {
        case sf::Keyboard::Space: keyReleased(Keyboard::SPACE); break;
        case sf::Keyboard::Q: keyReleased(Keyboard::Q); break;
        case sf::Keyboard::R: keyReleased(Keyboard::R); break;
        case sf::Keyboard::S: keyReleased(Keyboard::S); break;
        default:
            break;
        }
    }

}

void Keyboard::keyPressed(Keyboard::Keys key)
{
    uint32_t uKey = static_cast<uint32_t>(key);
    uint32_t mask = 0b1 << uKey;
    m_keyStates |= mask;
}

void Keyboard::keyReleased(Keys key)
{
    uint32_t uKey = static_cast<uint32_t>(key);
    uint32_t mask = ~(0b1 << uKey);
    m_keyStates &= mask;
}

bool Keyboard::isKeyPressed(Keys key)
{
    uint32_t uKey = static_cast<uint32_t>(key);
    uint32_t mask = 0b1 << uKey;
    return m_keyStates & mask;
}

bool Keyboard::isKeyReleased(Keys key)
{
    uint32_t uKey = static_cast<uint32_t>(key);
    uint32_t mask = 0b1 << uKey;
    return (m_keyStatesLastFrame & mask) && !(m_keyStates & mask);
}

}