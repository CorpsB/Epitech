/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(size_t pin)
{
    if (pin == 1)
        return False;
    return Undefined;
}

int nts::FalseComponent::getBounds()
{
    return 1;
}
