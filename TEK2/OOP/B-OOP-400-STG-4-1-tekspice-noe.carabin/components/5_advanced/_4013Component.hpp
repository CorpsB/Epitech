/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4013Component
*/

#ifndef _4013COMPONENT_HPP_
    #define _4013COMPONENT_HPP_
    #include "../1_required/DFlipFlopPRComponent.hpp"

namespace nts {
    class _4013Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            DFlipFlopPRComponent _f1;
            DFlipFlopPRComponent _f2;
    };
};

#endif /* !_4013COMPONENT_HPP_ */
