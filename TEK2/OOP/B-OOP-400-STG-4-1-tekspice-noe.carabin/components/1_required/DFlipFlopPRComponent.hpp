/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DFlipFlopPRComponent
*/

#ifndef DFLIPFLOPPRCOMPONENT_HPP_
    #define DFLIPFLOPPRCOMPONENT_HPP_
    #include "LATCH/DLatchPRComponent.hpp"
    #include "../3_elementary/NOT/NotComponent.hpp"

namespace nts {
    class DFlipFlopPRComponent : public AComponent {
        public:
            DFlipFlopPRComponent();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);

        private:
            DLatchPRComponent _d1;
            DLatchPRComponent _d2;
            NotComponent _not1;
            NotComponent _not2;
            NotComponent _not_pr;
            NotComponent _not_cl;
    };
};

#endif /* !DFLIPFLOPPRCOMPONENT_HPP_ */
