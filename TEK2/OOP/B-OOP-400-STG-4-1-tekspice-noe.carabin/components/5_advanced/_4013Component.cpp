/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4013Component
*/

#include "_4013Component.hpp"

void nts::_4013Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_f1.setLink(5, other, otherPin);
        else if (pin == 2)
            this->_f1.setLink(6, other, otherPin);
        else if (pin == 3)
            this->_f1.setLink(2, other, otherPin);
        else if (pin == 4)
            this->_f1.setLink(4, other, otherPin);
        else if (pin == 5)
            this->_f1.setLink(1, other, otherPin);
        else if (pin == 6)
            this->_f1.setLink(3, other, otherPin);
        else if (pin == 8)
            this->_f2.setLink(3, other, otherPin);
        else if (pin == 9)
            this->_f2.setLink(1, other, otherPin);
        else if (pin == 10)
            this->_f2.setLink(4, other, otherPin);
        else if (pin == 11)
            this->_f2.setLink(2, other, otherPin);
        else if (pin == 12)
            this->_f2.setLink(6, other, otherPin);
        else if (pin == 13)
            this->_f2.setLink(5, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4013Component::compute(size_t pin)
{
    if (pin == 1)
        return this->_f1.compute(5);
    if (pin == 2)
        return this->_f1.compute(6);
    if (pin == 12)
        return this->_f2.compute(6);
    if (pin == 13)
        return this->_f2.compute(5);
    return Undefined;
}

int nts::_4013Component::getBounds()
{
    return 14;
}
