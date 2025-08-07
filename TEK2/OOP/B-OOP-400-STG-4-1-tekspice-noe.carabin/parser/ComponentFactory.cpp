/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

#include "../components/2_special/ClockComponent.hpp"
#include "../components/2_special/FalseComponent.hpp"
#include "../components/2_special/TrueComponent.hpp"
#include "../components/2_special/InputComponent.hpp"
#include "../components/2_special/OutputComponent.hpp"

#include "../components/4_gates/_4001Component.hpp"
#include "../components/4_gates/_4011Component.hpp"
#include "../components/4_gates/_4030Component.hpp"
#include "../components/4_gates/_4071Component.hpp"
#include "../components/4_gates/_4081Component.hpp"
#include "../components/4_gates/_4069Component.hpp"

#include "../components/5_advanced/_4008Component.hpp"
#include "../components/5_advanced/_4013Component.hpp"
#include "../components/5_advanced/_4017Component.hpp"
#include "../components/5_advanced/LoggerComponent.hpp"
// #include "components/4_advanced/_4013Component.hpp"
// #include "components/4_advanced/_4017Component.hpp"
// #include "components/4_advanced/_4040Component.hpp"
// #include "components/4_advanced/_4094Component.hpp"
// #include "components/4_advanced/_4512Component.hpp"
// #include "components/4_advanced/_4514Component.hpp"
// #include "components/4_advanced/_4801Component.hpp"
// #include "components/4_advanced/_2716Component.hpp"

nts::ComponentFactory::ComponentFactory()
{
    this->_factory["input"] = []() { return std::make_unique<InputComponent>(); };
    this->_factory["output"] = []() { return std::make_unique<OutputComponent>(); };
    this->_factory["true"] = []() { return std::make_unique<TrueComponent>(); };
    this->_factory["false"] = []() { return std::make_unique<FalseComponent>(); };
    this->_factory["clock"] = []() { return std::make_unique<ClockComponent>(); };
    this->_factory["and"] = []() { return std::make_unique<AndComponent>(); };
    this->_factory["or"] = []() { return std::make_unique<OrComponent>(); };
    this->_factory["xor"] = []() { return std::make_unique<XorComponent>(); };
    this->_factory["not"] = []() { return std::make_unique<NotComponent>(); };
    this->_factory["4001"] = []() { return std::make_unique<_4001Component>(); };
    this->_factory["4011"] = []() { return std::make_unique<_4011Component>(); };
    this->_factory["4030"] = []() { return std::make_unique<_4030Component>(); };
    this->_factory["4069"] = []() { return std::make_unique<_4069Component>(); };
    this->_factory["4071"] = []() { return std::make_unique<_4071Component>(); };
    this->_factory["4081"] = []() { return std::make_unique<_4081Component>(); };
    this->_factory["logger"] = [] () { return std::make_unique<LoggerComponent>(); };
    this->_factory["4008"] = []() { return std::make_unique<_4008Component>(); };
    this->_factory["4013"] = []() { return std::make_unique<_4013Component>(); };
    this->_factory["4017"] = []() { return std::make_unique<_4017Component>(); };
    // this->_factory["4040"] = []() { return std::make_unique<_4040Component>(); };
    // this->_factory["4094"] = []() { return std::make_unique<_4094Component>(); };
    // this->_factory["4512"] = []() { return std::make_unique<_4512Component>(); };
    // this->_factory["4514"] = []() { return std::make_unique<_4514Component>(); };
    // this->_factory["4801"] = []() { return std::make_unique<_4801Component>(); };
    // this->_factory["2716"] = []() { return std::make_unique<_2716Component>(); };
    // this->_factory["logger"] = []() { return std::make_unique<LoggerComponent>(); };

}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComp(const std::string &type)
{
    auto it = _factory.find(type);

    if (it != _factory.end()) {
        return it->second();
    }
    return nullptr;
}

