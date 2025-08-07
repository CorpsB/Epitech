/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** Nts
*/

#include "Nts.hpp"
#include "components/5_advanced/LoggerComponent.hpp"

nts::Nts::Nts() : _ticks(0) {}

std::ostream &operator<<(std::ostream &s, nts::Tristate v)
{
    if (v == nts::Tristate::True)
        s << '1';
    else if (v == nts::Tristate::False)
        s << '0';
    else
        s << 'U';
    return s;
}

void nts::Nts::addComponent(const std::string &name, std::unique_ptr<IComponent> component, const std::string &type)
{
    IComponent *tmp;

    if (component == nullptr)
        throw nts::Nts::Error("Unknown component type.");
    this->_components[name] = std::move(component);

    tmp = this->_components[name].get();

    if (type == "input" || type == "clock")
        this->_inputs.push_back(tmp);
    if (type == "output")
        this->_outputs.push_back(tmp);
    if (type == "logger")
        this->_loggers.push_back(tmp);
}

nts::IComponent *nts::Nts::getComponent(const std::string &name) const
{
    if (this->_components.find(name) != this->_components.end())
        return this->_components.at(name).get();
    return nullptr;
}

void nts::Nts::simulate()
{
    ++this->_ticks;
    for (const auto &pair : this->_components)
        pair.second.get()->simulate();
    for (IComponent *it : this->_loggers) {
        nts::LoggerComponent *smartComp = dynamic_cast<nts::LoggerComponent *>(it);
        if (smartComp) {
            smartComp->execute();
        } else {
            throw nts::Nts::Error("Dynamic cast exception.");
        }
    }
    for (nts::IComponent *compPtr : this->_outputs)
        compPtr->getLink(1);
}

void nts::Nts::display() const
{
    std::cout << "tick: " << this->_ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    for (nts::IComponent *compPtr : this->_inputs) {
        for (const auto &pair : this->_components) {
            if (pair.second.get() == compPtr) {
                nts::SmartComponent *smartComp = dynamic_cast<nts::SmartComponent *>(pair.second.get());
                if (smartComp) {
                    std::cout << "  " << pair.first << ": " << smartComp->getState() << std::endl;
                } else {
                    throw nts::Nts::Error("Dynamic cast exception.");
                }
            }
        }
    }
    std::cout << "output(s):" << std::endl;
    for (nts::IComponent *compPtr : this->_outputs)
        for (const auto &pair : this->_components)
            if (pair.second.get() == compPtr)
                std::cout << "  " << pair.first << ": " << compPtr->getLink(1) << std::endl;
}

void nts::Nts::launch()
{
    std::string line;
    while(true) {
        std::cout << "> ";
        std::getline(std::cin, line);
  
        if (line == "display") {
            this->display();
        } else if (line == "exit" || std::cin.eof()) {
            break;
        } else if (line == "simulate") {
            this->simulate();
        } else if (line == "loop") {
            this->loop();
        } else if (!this->isInputChange(this->_inputs, line, this->_components)) {
            std::cerr << "Invalid input, please check and retry" << std::endl;
        }
    }
}

void nts::Nts::loop()
{
    while(true) {
        this->simulate();
        this->display();
    }
}
