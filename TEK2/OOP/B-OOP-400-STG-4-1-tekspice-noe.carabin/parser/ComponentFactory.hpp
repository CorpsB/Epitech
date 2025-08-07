/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
    #define COMPONENTFACTORY_HPP_
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <map>
    #include <functional>
    #include <memory>
    #include "../components/IComponent.hpp"

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            std::unique_ptr<IComponent> createComp(const std::string &type);

        private:
            std::map<std::string, std::function<std::unique_ptr<IComponent>()>> _factory;
    };
};

#endif /* !COMPONENTFACTORY_HPP_ */
