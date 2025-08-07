/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
    #define FALSECOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !FALSECOMPONENT_HPP_ */
