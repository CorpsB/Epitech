/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4081Component
*/

#ifndef _4081COMPONENT_HPP_
    #define _4081COMPONENT_HPP_
    #include "../3_elementary/AND/AndComponent.hpp"

namespace nts {
    class _4081Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            AndComponent _and1;
            AndComponent _and2;
            AndComponent _and3;
            AndComponent _and4;
    };
};

#endif /* !_4081COMPONENT_HPP_ */
