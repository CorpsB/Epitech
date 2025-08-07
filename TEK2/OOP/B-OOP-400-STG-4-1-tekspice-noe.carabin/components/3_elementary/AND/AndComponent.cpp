/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(size_t pin)
{
    if (pin != 3)
        return Undefined;
    return LogicalComponent::And(this->getLink(1), this->getLink(2));
}

int nts::AndComponent::getBounds()
{
    return 3;
}
