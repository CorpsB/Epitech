/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LoopComponent
*/

#ifndef LOOPCOMPONENT_HPP_
    #define LOOPCOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class LoopComponent : public AComponent {
        public:
            LoopComponent(Tristate value);
            Tristate compute(size_t pin);

        private:
            Tristate _value;
    };
};

#endif /* !LOOPCOMPONENT_HPP_ */
