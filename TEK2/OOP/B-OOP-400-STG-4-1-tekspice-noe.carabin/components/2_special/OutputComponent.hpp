/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
    #define OUTPUTCOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
        public:
            Tristate compute(size_t pin);
            int getBounds();
    };
};

#endif /* !OUTPUTCOMPONENT_HPP_ */
