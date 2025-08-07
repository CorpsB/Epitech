/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
    #define TRUECOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !TRUECOMPONENT_HPP_ */
