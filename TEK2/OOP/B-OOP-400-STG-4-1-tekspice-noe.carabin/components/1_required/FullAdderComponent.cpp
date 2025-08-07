/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** FullAdderComponent
*/

#include "FullAdderComponent.hpp"

nts::FullAdderComponent::FullAdderComponent()
{
    this->_xor2.setLink(1, this->_xor1, 3);
    this->_and2.setLink(1, this->_xor1, 3);
    this->_or1.setLink(1, this->_and2, 3);
    this->_or1.setLink(2, this->_and1, 3);
}

void nts::FullAdderComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1 || pin == 2) {
            this->_xor1.setLink(pin, other, otherPin);
            this->_and1.setLink(pin, other, otherPin);
        }
        if (pin == 3) {
            this->_xor2.setLink(2, other, otherPin);
            this->_and2.setLink(2, other, otherPin);
        }
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::FullAdderComponent::compute(size_t pin)
{
    if (pin == 4)
        return this->_xor2.compute(3);
    if (pin == 5)
        return this->_or1.compute(3);
    return Undefined;
}
