/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NorComponent
*/

#include "NorComponent.hpp"

nts::Tristate nts::NorComponent::compute(size_t pin)
{
    if (pin != 3)
        return Undefined;
    return LogicalComponent::Nor(this->getLink(1), this->getLink(2));
}

int nts::NorComponent::getBounds()
{
    return 3;
}
