/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** NandComponent
*/

#ifndef NANDCOMPONENT_HPP_
    #define NANDCOMPONENT_HPP_
    #include "../../AComponent.hpp"

namespace nts {
    class NandComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !NANDCOMPONENT_HPP_ */
