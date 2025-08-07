/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** OrComponent
*/

#include "OrComponent.hpp"

nts::Tristate nts::OrComponent::compute(size_t pin)
{
    if (pin != 3)
        return Undefined;
    return LogicalComponent::Or(this->getLink(1), this->getLink(2));
}

int nts::OrComponent::getBounds()
{
    return 3;
}
