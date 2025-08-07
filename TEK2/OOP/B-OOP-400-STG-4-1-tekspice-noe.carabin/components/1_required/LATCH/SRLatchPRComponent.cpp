/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** SRLatchPRComponent
*/

#include "SRLatchPRComponent.hpp"

nts::SRLatchPRComponent::SRLatchPRComponent() : _q(False), _qbar(True)
{
    this->_q.setLink(1, this->_nand3_1, 4);
    this->_qbar.setLink(1, this->_nand3_2, 4);
    this->_nand3_1.setLink(3, this->_qbar, 3);
    this->_nand3_2.setLink(1, this->_q, 3);
}

void nts::SRLatchPRComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 1)
            this->_nand3_1.setLink(1, other, otherPin);
        else if (pin == 2)
            this->_nand3_2.setLink(3, other, otherPin);
        else if (pin == 3)
            this->_nand3_1.setLink(2, other, otherPin);
        else if (pin == 4)
            this->_nand3_2.setLink(2, other, otherPin);
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::SRLatchPRComponent::compute(size_t pin)
{
    Tristate q = this->_q.compute(2);
    Tristate qbar = this->_qbar.compute(2);

    if (pin == 5)
        return q;
    if (pin == 6)
        return qbar;
    return Undefined;
}
