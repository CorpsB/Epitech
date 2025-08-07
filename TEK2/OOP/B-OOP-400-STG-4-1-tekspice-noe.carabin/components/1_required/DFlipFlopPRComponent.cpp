/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DFlipFlopPRComponent
*/

#include "DFlipFlopPRComponent.hpp"

nts::DFlipFlopPRComponent::DFlipFlopPRComponent()
{
    this->_d1.setLink(2, this->_not2, 2);
    this->_d1.setLink(3, this->_not1, 2);
    this->_d1.setLink(4, this->_not_pr, 2);
    this->_d1.setLink(5, this->_not_cl, 2);
    this->_d2.setLink(1, this->_d1, 6);
    this->_d2.setLink(3, this->_d1, 7);
    this->_d2.setLink(4, this->_not_pr, 2);
    this->_d2.setLink(5, this->_not_cl, 2);
}

void nts::DFlipFlopPRComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1) {
            this->_d1.setLink(1, other, otherPin);
            this->_not1.setLink(1, other, otherPin);
        } else if (pin == 2) {
            this->_not2.setLink(1, other, otherPin);
            this->_d2.setLink(2, other, otherPin);
        } else if (pin == 3)
            this->_not_pr.setLink(1, other, otherPin);
        else if (pin == 4)
            this->_not_cl.setLink(1, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::DFlipFlopPRComponent::compute(size_t pin)
{
    if (pin == 5)
        return this->_d2.compute(6);
    if (pin == 6)
        return this->_d2.compute(7);
    return Undefined;
}
