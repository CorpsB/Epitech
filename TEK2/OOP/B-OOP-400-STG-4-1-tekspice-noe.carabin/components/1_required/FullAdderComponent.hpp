/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** FullAdderComponent
*/

#ifndef FULLADDERCOMPONENT_HPP_
    #define FULLADDERCOMPONENT_HPP_
    #include "../3_elementary/AND/AndComponent.hpp"
    #include "../3_elementary/OR/OrComponent.hpp"
    #include "../3_elementary/XOR/XorComponent.hpp"

namespace nts {
    class FullAdderComponent : public AComponent {
        public:
            FullAdderComponent();
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false);
            Tristate compute(size_t pin);

        private:
            XorComponent _xor1;
            XorComponent _xor2;
            AndComponent _and1;
            AndComponent _and2;
            OrComponent _or1;
    };
};

#endif /* !FULLADDERCOMPONENT_HPP_ */
