/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_
    #include <unordered_map>
    #include "IComponent.hpp"
    #include "0_base/LogicalComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent() = default;

            int getBounds() override { return 0; };
            void simulate() override {};
            Tristate getLink(size_t pin) const override;
            void setLink(size_t pin, IComponent &other, size_t otherPin, bool rev = false) override;

        protected:
            std::unordered_map<size_t, std::pair<size_t, nts::IComponent *>> _links;
    };
};

#endif /* !ACOMPONENT_HPP_ */
