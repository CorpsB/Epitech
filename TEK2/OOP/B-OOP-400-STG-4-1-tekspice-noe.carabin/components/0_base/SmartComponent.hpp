/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** SmartComponent
*/

#ifndef SMARTCOMPONENT_HPP_
#define SMARTCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts {
    class SmartComponent : public AComponent { 
        public:
            SmartComponent();

            void setState(Tristate state);
            Tristate compute(size_t pin);
            void simulate();
            Tristate getState();
            Tristate getNext();
            int getBounds();

        protected:
            Tristate _next;
            Tristate _state;
            bool reset;
    };
};
#endif /* !SMARTCOMPONENT_HPP_ */
