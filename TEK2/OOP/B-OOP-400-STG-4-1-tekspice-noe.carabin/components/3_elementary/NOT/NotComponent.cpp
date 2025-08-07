/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(size_t pin)
{
    if (pin != 2)
        return Undefined;
    return LogicalComponent::Not(this->getLink(1));
}

int nts::NotComponent::getBounds()
{
    return 2;
}
