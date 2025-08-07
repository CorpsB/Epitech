/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DLatchPRComponent
*/

#include "DLatchPRComponent.hpp"

nts::DLatchPRComponent::DLatchPRComponent()
{
    this->_sr1.setLink(1, this->_nand1, 3);
    this->_sr1.setLink(2, this->_nand2, 3);
}

void nts::DLatchPRComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_nand1.setLink(1, other, otherPin);
        else if (pin == 2) {
            this->_nand1.setLink(2, other, otherPin);
            this->_nand2.setLink(1, other, otherPin);
        } else if (pin == 3)
            this->_nand2.setLink(2, other, otherPin);
        else if (pin == 4)
            this->_sr1.setLink(3, other, otherPin);
        else if (pin == 5)
            this->_sr1.setLink(4, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::DLatchPRComponent::compute(size_t pin)
{
    if (pin == 6)
        return this->_sr1.compute(5);
    if (pin == 7)
        return this->_sr1.compute(6);
    return Undefined;
}
