/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NandComponent
*/

#include "NandComponent.hpp"

nts::Tristate nts::NandComponent::compute(size_t pin)
{
    if (pin != 3)
        return Undefined;
    return LogicalComponent::Nand(this->getLink(1), this->getLink(2));
}

int nts::NandComponent::getBounds()
{
    return 3;
}
