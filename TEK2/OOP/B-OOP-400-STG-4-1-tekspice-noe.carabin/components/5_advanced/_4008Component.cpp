/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4008Component
*/

#include "_4008Component.hpp"

nts::_4008Component::_4008Component()
{
    this->_f2.setLink(3, this->_f1, 5);
    this->_f3.setLink(3, this->_f2, 5);
    this->_f4.setLink(3, this->_f3, 5);
}

void nts::_4008Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 15)
            this->_f4.setLink(1, other, otherPin);
        else if (pin == 1)
            this->_f4.setLink(2, other, otherPin);
        else if (pin == 2)
            this->_f3.setLink(1, other, otherPin);
        else if (pin == 3)
            this->_f3.setLink(2, other, otherPin);
        else if (pin == 4)
            this->_f2.setLink(1, other, otherPin);
        else if (pin == 5)
            this->_f2.setLink(2, other, otherPin);
        else if (pin == 6)
            this->_f1.setLink(1, other, otherPin);
        else if (pin == 7)
            this->_f1.setLink(2, other, otherPin);
        else if (pin == 9)
            this->_f1.setLink(3, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4008Component::compute(size_t pin)
{
    if (pin == 10)
        return this->_f1.compute(4);
    if (pin == 11)
        return this->_f2.compute(4);
    if (pin == 12)
        return this->_f3.compute(4);
    if (pin == 13)
        return this->_f4.compute(4);
    if (pin == 14)
        return this->_f4.compute(5);
    return Undefined;
}

int nts::_4008Component::getBounds()
{
    return 16;
}
