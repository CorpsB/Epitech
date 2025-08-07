/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4081Component
*/

#include "_4081Component.hpp"

void nts::_4081Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_and1.setLink(1, other, otherPin);
        else if (pin == 2)
            this->_and1.setLink(2, other, otherPin);
        else if (pin == 5)
            this->_and2.setLink(1, other, otherPin);
        else if (pin == 6)
            this->_and2.setLink(2, other, otherPin);
        else if (pin == 8)
            this->_and3.setLink(1, other, otherPin);
        else if (pin == 9)
            this->_and3.setLink(2, other, otherPin);
        else if (pin == 12)
            this->_and4.setLink(1, other, otherPin);
        else if (pin == 13)
            this->_and4.setLink(2, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4081Component::compute(size_t pin)
{
    if (pin == 3)
        return this->_and1.compute(3);
    else if (pin == 4)
        return this->_and2.compute(3);
    else if (pin == 10)
        return this->_and3.compute(3);
    else if (pin == 11)
        return this->_and4.compute(3);
    return Undefined;
}

int nts::_4081Component::getBounds()
{
    return 14;
}
