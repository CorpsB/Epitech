/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** SmartComponent
*/

#include "SmartComponent.hpp"

nts::SmartComponent::SmartComponent() : _next(Undefined), _state(Undefined), reset(false)
{
}

void nts::SmartComponent::setState(Tristate state)
{
    this->reset = true;
    this->_next = state;
}

nts::Tristate nts::SmartComponent::compute(size_t pin)
{
    if (pin == 1)
        return this->_state;
    return Undefined;
}

void nts::SmartComponent::simulate()
{
    this->_state = this->_next;
}

nts::Tristate nts::SmartComponent::getNext()
{
    return this->_next;
}

int nts::SmartComponent::getBounds()
{
    return 1;
}

nts::Tristate nts::SmartComponent::getState()
{
    return this->_state;
}
