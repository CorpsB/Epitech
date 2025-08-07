/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LoopComponent
*/

#include "LoopComponent.hpp"

nts::LoopComponent::LoopComponent(Tristate value) : _value(value)
{
}

nts::Tristate nts::LoopComponent::compute(size_t pin)
{
    if (pin == 2) {
        this->_value = this->getLink(1);
        return this->_value;
    }
    if (pin == 3)
        return this->_value;
    return Undefined;
}
