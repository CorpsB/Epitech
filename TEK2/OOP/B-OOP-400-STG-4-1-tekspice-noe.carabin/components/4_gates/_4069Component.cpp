/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4069Component
*/

#include "_4069Component.hpp"

void nts::_4069Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_not1.setLink(1, other, otherPin);
        else if (pin == 3)
            this->_not2.setLink(1, other, otherPin);
        else if (pin == 5)
            this->_not3.setLink(1, other, otherPin);
        else if (pin == 9)
            this->_not4.setLink(1, other, otherPin);
        else if (pin == 11)
            this->_not5.setLink(1, other, otherPin);
        else if (pin == 13)
            this->_not6.setLink(1, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4069Component::compute(size_t pin)
{
    if (pin == 2)
        return this->_not1.compute(2);
    if (pin == 4)
        return this->_not2.compute(2);
    if (pin == 6)
        return this->_not3.compute(2);
    if (pin == 8)
        return this->_not4.compute(2);
    if (pin == 10)
        return this->_not5.compute(2);
    if (pin == 12)
        return this->_not6.compute(2);
    return Undefined;
}

int nts::_4069Component::getBounds()
{
    return 14;
}
