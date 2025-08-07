/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

void nts::ClockComponent::simulate()
{
    if (this->_state == Undefined || this->reset) {
        this->_state = this->_next;
        this->reset = false;
    } else if (this->_state == True)
        this->_state = False;
    else
        this->_state = True;
}
