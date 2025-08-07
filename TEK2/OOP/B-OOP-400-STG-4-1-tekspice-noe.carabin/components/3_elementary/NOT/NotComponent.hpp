/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
    #define NOTCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !NOTCOMPONENT_HPP_ */
