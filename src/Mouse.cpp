#include "Mouse.hpp"

namespace a_star {

Mouse::Mouse()
    : m_keyStates(0)
    , m_keyStatesLastFrame(0)
    , m_lastClickPosition({0, 0})
    , m_position({0, 0})
{
}

void Mouse::handleEvents(sf::Event& ev)
{
    if(ev.type == sf::Event::MouseButtonPressed)
    {
        switch(ev.mouseButton.button)
        {
        case sf::Mouse::Left: keyPressed(Mouse::LEFT); break;
        case sf::Mouse::Middle: keyPressed(Mouse::MIDDLE); break;
        case sf::Mouse::Right: keyPressed(Mouse::RIGHT); break;
        default:
            break;
        }

        m_lastClickPosition = { ev.mouseButton.x, ev.mouseButton.y };
    }
    else if(ev.type == sf::Event::MouseButtonReleased)
    {
        switch(ev.mouseButton.button)
        {
        case sf::Mouse::Left: keyReleased(Mouse::LEFT); break;
        case sf::Mouse::Middle: keyReleased(Mouse::MIDDLE); break;
        case sf::Mouse::Right: keyReleased(Mouse::RIGHT); break;
        default:
            break;
        }

        m_lastClickPosition = { ev.mouseButton.x, ev.mouseButton.y };
    }
    else if(ev.type == sf::Event::MouseMoved)
    {
        m_position.at(0) = ev.mouseMove.x;
        m_position.at(1) = ev.mouseMove.y;
    }
}

void Mouse::update()
{
    m_keyStatesLastFrame = m_keyStates;
}

void Mouse::keyPressed(Keys key)
{
    uint8_t uKey = static_cast<uint8_t>(key);
    uint8_t mask = 0b1 << uKey;
    m_keyStates |= mask;
}

void Mouse::keyReleased(Keys key)
{
    uint8_t uKey = static_cast<uint8_t>(key);
    uint8_t mask = ~(0b1 << uKey);
    m_keyStates &= mask;
}

bool Mouse::isKeyPressed(Keys key)
{
    uint8_t uKey = static_cast<uint8_t>(key);
    uint8_t mask = 0b1 << uKey;
    return m_keyStates & mask;
}

bool Mouse::isKeyReleased(Keys key)
{
    uint8_t uKey = static_cast<uint8_t>(key);
    uint8_t mask = 0b1 << uKey;
    return (m_keyStatesLastFrame & mask) && !(m_keyStates & mask);
}

const std::array<int, 2>& Mouse::getLastClickPosition() const
{
    return m_lastClickPosition;
}

const std::array<int, 2>& Mouse::getPosition() const
{
    return m_position;
}


}