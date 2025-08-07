/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
    #define ORCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !ORCOMPONENT_HPP_ */
