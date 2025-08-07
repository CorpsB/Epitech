/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !ANDCOMPONENT_HPP_ */
