/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** Nts
*/

#ifndef NTS_HPP_
    #define NTS_HPP_
    #include "components/0_base/SmartComponent.hpp"
    #include "parser/ComponentFactory.hpp"
    #include <memory>
    #include <vector>
    #include <string>
    #include <unordered_map>
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <sstream>

namespace nts {
    class Nts {
        public:
            class Error : public std::exception {
                public:
                    Error(const std::string &msg = "") : _msg(msg) {};
                    const char *what() const noexcept
                    {
                        return this->_msg.c_str();
                    }
                private:
                    std::string _msg;
            };

            Nts();
            void addComponent(const std::string &name, std::unique_ptr<IComponent> component, const std::string &type);
            nts::IComponent *getComponent(const std::string &name) const;
            void simulate();
            void display() const;

            void launch();
            void loop();

            void parsing(std::string filepath);
            void extractLink(std::ifstream &info);
            bool isInputChange(std::vector<nts::IComponent *> input_component, std::string line,
                std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &map);

        protected:
            std::unordered_map<std::string, std::unique_ptr<IComponent>> _components;
            std::vector<IComponent *> _inputs;
            std::vector<IComponent *> _outputs;
            std::vector<IComponent *> _loggers;

            size_t _ticks;
    };
};

std::ostream &operator<<(std::ostream &s, nts::Tristate v);

#endif /* !NTS_HPP_ */
