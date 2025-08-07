/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
    #define CLOCKCOMPONENT_HPP_
    #include "../0_base/SmartComponent.hpp"

namespace nts {
    class ClockComponent : public SmartComponent {
        public:
            void simulate();
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
