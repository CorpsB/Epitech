/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** 4011Component
*/

#ifndef _4011COMPONENT_HPP_
    #define _4011COMPONENT_HPP_
    #include "../3_elementary/NAND/NandComponent.hpp"

namespace nts {
    class _4011Component : public AComponent {
        public:
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);
            int getBounds();

        private:
            NandComponent _nand1;
            NandComponent _nand2;
            NandComponent _nand3;
            NandComponent _nand4;
    };
};

#endif /* !_4011COMPONENT_HPP_ */
