/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4069Component
*/

#ifndef _4069COMPONENT_HPP_
    #define _4069COMPONENT_HPP_
    #include "../3_elementary/NOT/NotComponent.hpp"

namespace nts {
    class _4069Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            NotComponent _not1;
            NotComponent _not2;
            NotComponent _not3;
            NotComponent _not4;
            NotComponent _not5;
            NotComponent _not6;
    };
};

#endif /* !_4069COMPONENT_HPP_ */
