/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** LogicalComponent
*/

#include "LogicalComponent.hpp"

nts::Tristate nts::LogicalComponent::Or(Tristate a, Tristate b)
{
    if (a == True || b == True)
        return True;
    if (a == Undefined || b == Undefined)
        return Undefined;
    return False;
}

nts::Tristate nts::LogicalComponent::Xor(Tristate a, Tristate b)
{
    if (a == Undefined || b == Undefined)
        return Undefined;
    if (a == b)
        return False;
    return True;
}

nts::Tristate nts::LogicalComponent::And(Tristate a, Tristate b)
{
    if (a == False || b == False)
        return False;
    if (a == Undefined || b == Undefined)
        return Undefined;
    return True;
}

nts::Tristate nts::LogicalComponent::Not(Tristate a)
{
    if (a == Undefined)
        return Undefined;
    if (a == True)
        return False;
    return True;
}

nts::Tristate nts::LogicalComponent::Nand(Tristate a, Tristate b)
{
    return LogicalComponent::Not(LogicalComponent::And(a, b));
}

nts::Tristate nts::LogicalComponent::Nor(Tristate a, Tristate b)
{
    return LogicalComponent::Not(LogicalComponent::Or(a, b));
}

nts::Tristate nts::LogicalComponent::Nand3(Tristate a, Tristate b, Tristate c)
{
    return LogicalComponent::Not(LogicalComponent::And(LogicalComponent::And(a, b), c));
}
