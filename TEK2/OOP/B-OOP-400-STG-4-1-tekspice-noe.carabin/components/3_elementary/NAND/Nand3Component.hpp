/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** Nand3Component
*/

#ifndef NAND3COMPONENT_HPP_
    #define NAND3COMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class Nand3Component : public AComponent {
        public:
            Tristate compute(size_t pin);
    };
};

#endif /* !NAND3COMPONENT_HPP_ */
