/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DFlipFlopPRLKComponent
*/

#ifndef DFLIPFLOPPRLKCOMPONENT_HPP_
    #define DFLIPFLOPPRLKCOMPONENT_HPP_
    #include "LATCH/DLatchPRComponent.hpp"
    #include "../3_elementary/NOT/NotComponent.hpp"

namespace nts {
    class DFlipFlopPRLKComponent : public AComponent {
        public:
            DFlipFlopPRLKComponent();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            void simulate();

        private:
            DLatchPRComponent _d1;
            DLatchPRComponent _d2;
            NotComponent _not1;
            NotComponent _not2;
            NotComponent _not_pr;
            NotComponent _not_cl;
            Tristate _q;
            Tristate _qbar;
            bool _lock1;
            bool _lock2;
    };
};

#endif /* !DFLIPFLOPPRLKCOMPONENT_HPP_ */
