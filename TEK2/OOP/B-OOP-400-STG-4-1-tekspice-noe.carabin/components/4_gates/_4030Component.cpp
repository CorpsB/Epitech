/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4030Component
*/

#include "_4030Component.hpp"

void nts::_4030Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_xor1.setLink(1, other, otherPin);
        else if (pin == 2)
            this->_xor1.setLink(2, other, otherPin);
        else if (pin == 5)
            this->_xor2.setLink(1, other, otherPin);
        else if (pin == 6)
            this->_xor2.setLink(2, other, otherPin);
        else if (pin == 8)
            this->_xor3.setLink(1, other, otherPin);
        else if (pin == 9)
            this->_xor3.setLink(2, other, otherPin);
        else if (pin == 12)
            this->_xor4.setLink(1, other, otherPin);
        else if (pin == 13)
            this->_xor4.setLink(2, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4030Component::compute(size_t pin)
{
    if (pin == 3)
        return this->_xor1.compute(3);
    else if (pin == 4)
        return this->_xor2.compute(3);
    else if (pin == 10)
        return this->_xor3.compute(3);
    else if (pin == 11)
        return this->_xor4.compute(3);
    return Undefined;
}

int nts::_4030Component::getBounds()
{
    return 14;
}
