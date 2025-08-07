/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4071Component
*/

#ifndef _4071COMPONENT_HPP_
    #define _4071COMPONENT_HPP_
    #include "../3_elementary/OR/OrComponent.hpp"

namespace nts {
    class _4071Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            OrComponent _or1;
            OrComponent _or2;
            OrComponent _or3;
            OrComponent _or4;
    };
};

#endif /* !_4071COMPONENT_HPP_ */
