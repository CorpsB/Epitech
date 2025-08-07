/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4030Component
*/

#ifndef _4030COMPONENT_HPP_
    #define _4030COMPONENT_HPP_
    #include "../3_elementary/XOR/XorComponent.hpp"

namespace nts {
    class _4030Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            XorComponent _xor1;
            XorComponent _xor2;
            XorComponent _xor3;
            XorComponent _xor4;
    };
};

#endif /* !_4030COMPONENT_HPP_ */
