/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** DLatchPRComponent
*/

#ifndef DLATCHPRCOMPONENT_HPP_
    #define DLATCHPRCOMPONENT_HPP_
    #include "SRLatchPRComponent.hpp"
    #include "../../3_elementary/NAND/NandComponent.hpp"
    #include "../../3_elementary/NOT/NotComponent.hpp"

namespace nts {
    class DLatchPRComponent : public AComponent {
        public:
            DLatchPRComponent();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);

        private:
            NandComponent _nand1;
            NandComponent _nand2;
            SRLatchPRComponent _sr1;
    };
};

#endif /* !DLATCHPRCOMPONENT_HPP_ */
