/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LoopLKComponent
*/

#include "LoopLKComponent.hpp"

nts::LoopLKComponent::LoopLKComponent(Tristate value) : _value(value), _locker(false)
{
}

nts::Tristate nts::LoopLKComponent::compute(size_t pin)
{
    if (pin == 2) {
        if (this->_locker == false) {
            this->_value = this->getLink(1);
            this->_locker = true;
        }
        return this->_value;
    }
    if (pin == 3)
        return this->_value;
    return Undefined;
}
