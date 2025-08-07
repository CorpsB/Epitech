/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
    #define LOGGERCOMPONENT_HPP_
    #include "../AComponent.hpp"

namespace nts {
    class LoggerComponent : public AComponent {
        public:
            void execute();
            Tristate compute( [[maybe_unused]] size_t pin) { return nts::Undefined;};
            int getBounds();
    };
};

#endif /* !LOGGERComponent_HPP_ */
