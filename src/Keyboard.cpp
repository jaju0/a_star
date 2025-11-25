#include "Keyboard.hpp"


namespace a_star {

Keyboard::Keyboard()
    : m_keyStates(0)
    , m_keyStatesLastFrame(0)
{
}

void Keyboard::handleEvents(sf::Event& ev)
{
    if(ev.type == sf::Event::KeyPressed)
    {
        switch(ev.key.code)
        {
        case sf::Keyboard::Space: keyPressed(Keyboard::SPACE); break;
        case sf::Keyboard::Q: keyPressed(Keyboard::Q); break;
        case sf::Keyboard::R: keyPressed(Keyboard::R); break;
        case sf::Keyboard::S: keyPressed(Keyboard::S); break;
        case sf::Keyboard::Y: keyPressed(Keyboard::Y); break;
        case sf::Keyboard::X: keyPressed(Keyboard::X); break;
        case sf::Keyboard::C: keyPressed(Keyboard::C); break;
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
        case sf::Keyboard::Y: keyReleased(Keyboard::Y); break;
        case sf::Keyboard::X: keyReleased(Keyboard::X); break;
        case sf::Keyboard::C: keyReleased(Keyboard::C); break;
        default:
            break;
        }
    }
}

void Keyboard::update()
{
    m_keyStatesLastFrame = m_keyStates;
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