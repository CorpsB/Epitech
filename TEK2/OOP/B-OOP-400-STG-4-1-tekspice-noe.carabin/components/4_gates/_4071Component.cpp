/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4071Component
*/

#include "_4071Component.hpp"

void nts::_4071Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_or1.setLink(1, other, otherPin);
        else if (pin == 2)
            this->_or1.setLink(2, other, otherPin);
        else if (pin == 5)
            this->_or2.setLink(1, other, otherPin);
        else if (pin == 6)
            this->_or2.setLink(2, other, otherPin);
        else if (pin == 8)
            this->_or3.setLink(1, other, otherPin);
        else if (pin == 9)
            this->_or3.setLink(2, other, otherPin);
        else if (pin == 12)
            this->_or4.setLink(1, other, otherPin);
        else if (pin == 13)
            this->_or4.setLink(2, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4071Component::compute(size_t pin)
{
    if (pin == 3)
        return this->_or1.compute(3);
    else if (pin == 4)
        return this->_or2.compute(3);
    else if (pin == 10)
        return this->_or3.compute(3);
    else if (pin == 11)
        return this->_or4.compute(3);
    return Undefined;
}

int nts::_4071Component::getBounds()
{
    return 14;
}
