/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DFlipFlopPRLKComponent
*/

#include "DFlipFlopPRLKComponent.hpp"

nts::DFlipFlopPRLKComponent::DFlipFlopPRLKComponent() : _lock1(false), _lock2(false)
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

void nts::DFlipFlopPRLKComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
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

nts::Tristate nts::DFlipFlopPRLKComponent::compute(size_t pin)
{
    if (pin == 5) {
        if (this->_lock1 == false) {
            this->_q = this->_d2.compute(6);
            this->_lock1 = true;
        }
        return this->_q;
    }
    if (pin == 6) {
        if (this->_lock2 == false) {
            this->_qbar = this->_d2.compute(7);
            this->_lock2 = true;
        }
        return this->_qbar;
    }
    return Undefined;
}

void nts::DFlipFlopPRLKComponent::simulate()
{
    this->_lock1 = false;
    this->_lock2 = false;
}
