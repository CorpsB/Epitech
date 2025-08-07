/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4017Component
*/

#include "_4017Component.hpp"

nts::_4017Component::_4017Component() : _loop59(False), _loop23(True)
{
    this->_and1.setLink(1, this->_not1, 2);

    // PRESET
    this->_f1.setLink(3, this->_false, 1);
    this->_f2.setLink(3, this->_false, 1);
    this->_f3.setLink(3, this->_false, 1);
    this->_f4.setLink(3, this->_false, 1);
    this->_f5.setLink(3, this->_false, 1);

    // CLOCK
    this->_f1.setLink(2, this->_and1, 3);
    this->_f2.setLink(2, this->_and1, 3);
    this->_f3.setLink(2, this->_and1, 3);
    this->_f4.setLink(2, this->_and1, 3);
    this->_f5.setLink(2, this->_and1, 3);

    // LINKS
    this->_nor0.setLink(1, this->_f5, 5);
    this->_nor0.setLink(2, this->_f1, 5);
    this->_nor1.setLink(1, this->_f2, 5);
    this->_nor1.setLink(2, this->_f1, 6);
    this->_nor2.setLink(1, this->_f2, 6);
    this->_nor2.setLink(2, this->_f3, 5);
    this->_nor3.setLink(1, this->_f4, 5);
    this->_nor3.setLink(2, this->_f3, 6);
    this->_nor4.setLink(1, this->_f5, 5);
    this->_nor4.setLink(2, this->_f4, 6);
    this->_nor5.setLink(1, this->_f1, 6);
    this->_nor5.setLink(2, this->_loop59, 2);
    this->_nor6.setLink(1, this->_f1, 5);
    this->_nor6.setLink(2, this->_f2, 6);
    this->_nor7.setLink(1, this->_f2, 5);
    this->_nor7.setLink(2, this->_f3, 6);
    this->_nor8.setLink(1, this->_f4, 6);
    this->_nor8.setLink(2, this->_f3, 5);
    this->_nor9.setLink(1, this->_f4, 5);
    this->_nor9.setLink(2, this->_loop59, 2);

    // UP_CYCLE
    this->_or1.setLink(1, this->_loop23, 3);
    this->_or1.setLink(2, this->_f1, 5);
    this->_and2.setLink(1, this->_or1, 3);
    this->_and2.setLink(2, this->_f2, 5);

    // F_ENTRIES
    this->_loop23.setLink(1, this->_f3, 5);
    this->_loop59.setLink(1, this->_f5, 6);
    this->_f1.setLink(1, this->_loop59, 3);
    this->_f2.setLink(1, this->_f1, 5);
    this->_f3.setLink(1, this->_and2, 3);
    this->_f4.setLink(1, this->_loop23, 2);
    this->_f5.setLink(1, this->_f4, 5);
}

void nts::_4017Component::setLink(size_t pin, IComponent &other, size_t otherPin, bool rev)
{
    this->_links[pin] = {otherPin, &other};

    if (!rev) {
        if (pin == 13)
            this->_not1.setLink(1, other, otherPin);
        else if (pin == 14)
            this->_and1.setLink(2, other, otherPin);
        else if (pin == 15) { // RESET
            this->_f1.setLink(4, other, otherPin);
            this->_f2.setLink(4, other, otherPin);
            this->_f3.setLink(4, other, otherPin);
            this->_f4.setLink(4, other, otherPin);
            this->_f5.setLink(4, other, otherPin);
        }
        other.setLink(otherPin, *this, pin, true);
    }
}

nts::Tristate nts::_4017Component::compute(size_t pin)
{
    if (pin == 3)
        return this->_nor0.compute(3);
    if (pin == 2)
        return this->_nor1.compute(3);
    if (pin == 4)
        return this->_nor2.compute(3);
    if (pin == 7)
        return this->_nor3.compute(3);
    if (pin == 10)
        return this->_nor4.compute(3);
    if (pin == 1)
        return this->_nor5.compute(3);
    if (pin == 5)
        return this->_nor6.compute(3);
    if (pin == 6)
        return this->_nor7.compute(3);
    if (pin == 9)
        return this->_nor8.compute(3);
    if (pin == 11)
        return this->_nor9.compute(3);
    if (pin == 12)
        return this->_loop59.compute(2);
    return Undefined;
}

void nts::_4017Component::simulate()
{
    this->_f1.simulate();
    this->_f2.simulate();
    this->_f3.simulate();
    this->_f4.simulate();
    this->_f5.simulate();
    this->_loop23.simulate();
    this->_loop59.simulate();
}

int nts::_4017Component::getBounds()
{
    return 16;
}
