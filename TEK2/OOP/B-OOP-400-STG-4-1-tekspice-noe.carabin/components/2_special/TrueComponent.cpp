/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(size_t pin)
{
    if (pin == 1)
        return True;
    return Undefined;
}

int nts::TrueComponent::getBounds()
{
    return 1;
}
