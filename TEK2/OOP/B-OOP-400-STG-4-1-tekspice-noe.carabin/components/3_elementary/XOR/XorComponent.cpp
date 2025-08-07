/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::Tristate nts::XorComponent::compute(size_t pin)
{
    if (pin != 3)
        return Undefined;
    return LogicalComponent::Xor(this->getLink(1), this->getLink(2));
}

int nts::XorComponent::getBounds()
{
    return 3;
}
