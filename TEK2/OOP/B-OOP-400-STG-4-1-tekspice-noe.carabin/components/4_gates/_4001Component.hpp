/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4001Component
*/

#ifndef _4001COMPONENT_HPP_
    #define _4001COMPONENT_HPP_
    #include "../3_elementary/NOR/NorComponent.hpp"

namespace nts {
    class _4001Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            NorComponent _nor1;
            NorComponent _nor2;
            NorComponent _nor3;
            NorComponent _nor4;
    };
};

#endif /* !_4001COMPONENT_HPP_ */
