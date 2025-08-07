/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** SRLatchPRComponent
*/

#ifndef SRLATCHPRCOMPONENT_HPP_
    #define SRLATCHPRCOMPONENT_HPP_
    #include "../../0_base/LoopComponent.hpp"
    #include "../../3_elementary/NAND/Nand3Component.hpp"

namespace nts {
    class SRLatchPRComponent : public AComponent {
        public:
            SRLatchPRComponent();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);

        private:
            LoopComponent _q;
            LoopComponent _qbar;
            Nand3Component _nand3_1;
            Nand3Component _nand3_2;
    };
};

#endif /* !SRLATCHPRCOMPONENT_HPP_ */
