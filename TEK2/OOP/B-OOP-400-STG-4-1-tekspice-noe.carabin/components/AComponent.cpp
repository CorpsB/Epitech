/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev)
        other.setLink(otherPin, *this, pin, true);
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    if (this->_links.find(pin) != this->_links.end())
        return this->_links.at(pin).second->compute(this->_links.at(pin).first);
    return Undefined;
}
