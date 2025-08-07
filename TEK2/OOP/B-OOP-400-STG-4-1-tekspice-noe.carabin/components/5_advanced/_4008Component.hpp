/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4008Component
*/

#ifndef _4008COMPONENT_HPP_
    #define _4008COMPONENT_HPP_
    #include "../1_required/FullAdderComponent.hpp"

namespace nts {
    class _4008Component : public AComponent {
        public:
            _4008Component();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            FullAdderComponent _f1;
            FullAdderComponent _f2;
            FullAdderComponent _f3;
            FullAdderComponent _f4;
    };
};

#endif /* !_4008COMPONENT_HPP_ */
