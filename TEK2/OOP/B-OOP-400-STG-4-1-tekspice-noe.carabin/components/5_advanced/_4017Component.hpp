/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** _4017Component
*/

#ifndef _4017COMPONENT_HPP_
    #define _4017COMPONENT_HPP_
    #include "../1_required/DFlipFlopPRLKComponent.hpp"
    #include "../3_elementary/OR/OrComponent.hpp"
    #include "../3_elementary/AND/AndComponent.hpp"
    #include "../3_elementary/NOR/NorComponent.hpp"
    #include "../2_special/FalseComponent.hpp"
    #include "../0_base/LoopLKComponent.hpp"

namespace nts {
    class _4017Component : public AComponent {
        public:
            _4017Component();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();
            void simulate();

        private:
            DFlipFlopPRLKComponent _f1;
            DFlipFlopPRLKComponent _f2;
            DFlipFlopPRLKComponent _f3;
            DFlipFlopPRLKComponent _f4;
            DFlipFlopPRLKComponent _f5;
            LoopLKComponent _loop59;
            LoopLKComponent _loop23;
            FalseComponent _false;
            OrComponent _or1;
            AndComponent _and1;
            AndComponent _and2;
            NotComponent _not1;
            NorComponent _nor0;
            NorComponent _nor1;
            NorComponent _nor2;
            NorComponent _nor3;
            NorComponent _nor4;
            NorComponent _nor5;
            NorComponent _nor6;
            NorComponent _nor7;
            NorComponent _nor8;
            NorComponent _nor9;
    };
};

#endif /* !_4017COMPONENT_HPP_ */
