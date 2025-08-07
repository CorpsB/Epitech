/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** Nand3Component
*/

#include "Nand3Component.hpp"

nts::Tristate nts::Nand3Component::compute(size_t pin)
{
    if (pin != 4)
        return Undefined;
    return LogicalComponent::Nand3(this->getLink(1), this->getLink(2), this->getLink(3));
}
