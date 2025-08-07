/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LoopLKComponent
*/

#ifndef LOOPLKCOMPONENT_HPP_
    #define LOOPLKCOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class LoopLKComponent : public AComponent {
        public:
            LoopLKComponent(Tristate value);
            Tristate compute(size_t pin);

        private:
            Tristate _value;
            bool _locker;
    };
};

#endif /* !LOOPLKCOMPONENT_HPP_ */
