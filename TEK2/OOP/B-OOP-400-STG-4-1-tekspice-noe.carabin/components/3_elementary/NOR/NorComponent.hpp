/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NorComponent
*/

#ifndef NORCOMPONENT_HPP_
    #define NORCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class NorComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !NORCOMPONENT_HPP_ */
