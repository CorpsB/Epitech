/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>

namespace nts {
    enum Tristate {
        False = false,
        True = true,
        Undefined = (-true)
    };

    class IComponent {
        public:
            IComponent() = default;
            virtual ~IComponent() = default;

            virtual Tristate getLink(size_t pin) const = 0;
            virtual void simulate() = 0;
            virtual void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false) = 0;
            virtual Tristate compute(size_t pin) = 0;
            virtual int getBounds() = 0;
    };
};

#endif /* !ICOMPONENT_HPP_ */
