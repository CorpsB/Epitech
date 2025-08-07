/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** LogicalComponent
*/

#ifndef LogicalCOMPONENT_HPP_
    #define LogicalCOMPONENT_HPP_
    #include "../IComponent.hpp"

namespace nts {
    class LogicalComponent {
        public:
            static Tristate Or(Tristate a, Tristate b);
            static Tristate Xor(Tristate a, Tristate b);
            static Tristate And(Tristate a, Tristate b);
            static Tristate Not(Tristate a);
            static Tristate Nand(Tristate a, Tristate b);
            static Tristate Nor(Tristate a, Tristate b);

            static Tristate Nand3(Tristate a, Tristate b, Tristate c);
    };
}

#endif /* !LogicalCOMPONENT_HPP_ */
