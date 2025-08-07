/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !XORCOMPONENT_HPP_ */
