/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** Nts
*/

#include "../Nts.hpp"

std::vector<std::string> stdStringToArray(std::string src, std::string separator)
{
    size_t start = 0;
    size_t end;
    std::string result;
    std::vector<std::string> table;

    while ((end = src.find(separator, start)) != std::string::npos) {
        result = src.substr(start, end - start);
        start = end + separator.size();
        table.push_back(result);
    }
    table.push_back(src.substr(start));
    return table;
}

bool isNameAlreadyUsed(std::string name, std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->first  == name)
            return true;
    }
    return false;
}

void isCorrectExtension(std::string filepath)
{
    if (filepath.size() >= 4 && filepath.substr(filepath.size() - 4) != ".nts")
        throw nts::Nts::Error("Unknown extension file.");
}

bool findChipset(std::ifstream &info)
{
    std::string line;
    bool chipsets;

    for(;std::getline(info, line);) {
        if (line.find('#') < line.find(".chipsets:"))
            continue;
        if (line.find(".links:") != std::string::npos)
            throw nts::Nts::Error("Sections are in the wrong order.");
        if (line.find(".chipsets:") != std::string::npos) {
            chipsets = true;
            break;
        }
    }
    return chipsets;
}

void completeArgs(std::string line, std::string &name, std::string &type)
{
    std::string other;
    std::istringstream info(line);

    if (info >> type >> name) {
        if (info >> other)
            throw nts::Nts::Error("Too many arguments on a component declaration.");
    } else {
        throw nts::Nts::Error("Not enough arguments on a component declaration.");
    }
}

void nts::Nts::parsing(std::string filepath)
{
    std::ifstream info(filepath);
    std::string line;
    std::string lineWithoutComment;
    nts::ComponentFactory facto;

    bool link = false;
    bool iscomponent = false;

    std::string name;
    std::string type;
    std::string other;
    int nbspace;
    int nbtab;

    isCorrectExtension(filepath);
    if (!info.is_open())
        throw Nts::Error("No such file or directory.");

    //Déplace la lecture jusqu'au .chipsets
    if (!findChipset(info))
        throw Nts::Error("No .chipset section found.");
    for(; std::getline(info, line);) {
        if (line.find(".links:") != std::string::npos) {
            link = true;
            break;
        }
        if (line == "" || line.find('#') == 0)
            continue;
        lineWithoutComment = stdStringToArray(line, "#")[0];
        nbspace = std::count(lineWithoutComment.begin(), lineWithoutComment.end(), ' ');
        nbtab = std::count(lineWithoutComment.begin(), lineWithoutComment.end(), '\t');
        if (nbspace + nbtab == lineWithoutComment.length())
            continue;
        completeArgs(lineWithoutComment, name, type);
        if (isNameAlreadyUsed(name, this->_components))
            throw nts::Nts::Error("Two components cannot have the same Name.");
        addComponent(name, facto.createComp(type), type);
        iscomponent = true;
    }
    if (iscomponent == false)
        throw nts::Nts::Error("No component declaration.");
    if (link)
        this->extractLink(info);
    info.close();
}

void completeLinkArgs(const std::string &line, std::string &name1, size_t &nbr1, std::string &name2, size_t &nbr2)
{
    std::istringstream info(line);
    std::string tmp, tmp2, other;

    if (info >> tmp >> tmp2) {
        if (info >> other)
            throw nts::Nts::Error("Too many link arguments.");
        if (tmp.find(':') == std::string::npos || tmp2.find(':') == std::string::npos)
            throw nts::Nts::Error("Link error : You used an uninitialized entity.");

        try {
            name1 = tmp.substr(0, tmp.find(':'));
            nbr1 = std::stoi(tmp.substr(tmp.find(':') + 1));
            name2 = tmp2.substr(0, tmp2.find(':'));
            nbr2 = std::stoi(tmp2.substr(tmp2.find(':') + 1));

        } catch (const std::exception &e) {
            throw nts::Nts::Error("Invalid format, please use an int after ':' on the link section.");
        }
    } else {
        throw nts::Nts::Error("Not enough link arguments.");
    }
}

void findError(std::string name1, std::string name2, std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    bool isFirstExist = false;
    bool isSecondExist = false;

    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->first  == name1)
            isFirstExist = true;
        if (it->first  == name2)
            isSecondExist = true;
    }
    if (!isFirstExist || !isSecondExist)
        throw nts::Nts::Error("Link error : You used an uninitialized entity.");
}

void createLink(std::string name1, size_t nbr1, std::string name2, size_t nbr2, std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    for (auto it = map.begin(); it != map.end(); it++)
        if (it->first == name2)
            it->second.get()->setLink(nbr2, *map[name1].get(), nbr1);
}

void nts::Nts::extractLink(std::ifstream &info)
{
    std::string lineWithoutComment;
    std::string name1;
    std::string name2;
    size_t nbr1;
    size_t nbr2;
    int nbspace;
    int nbtab;

    for(std::string line; std::getline(info, line);) {
        if (line == "" || line.find('#') == 0)
            continue;
        lineWithoutComment = stdStringToArray(line, "#")[0];
        nbspace = std::count(lineWithoutComment.begin(), lineWithoutComment.end(), ' ');
        nbtab = std::count(lineWithoutComment.begin(), lineWithoutComment.end(), '\t');
        if (nbspace + nbtab == lineWithoutComment.length())
            continue;
        completeLinkArgs(lineWithoutComment, name1, nbr1, name2, nbr2);
        findError(name1, name2, this->_components);

        if (this->_components[name1].get()->getBounds() < nbr1)
            throw Nts::Error(name1 + " is out of bounds.");
        if (this->_components[name2].get()->getBounds() < nbr2)
            throw Nts::Error(name2 + " is out of bounds.");
        createLink(name1, nbr1, name2, nbr2, this->_components);
    }
}

bool nts::Nts::isInputChange(std::vector<nts::IComponent *> input_component, std::string line, std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    std::vector<std::string> input;
    nts::Tristate tristate;

    if (line.find('=') == std::string::npos)
        return false;
    input = stdStringToArray(line, "=");
    if (input.size() >= 3 || input.size() < 2)
        return false;

    if (input.at(1) == "0")
        tristate = nts::False;
    else if (input.at(1) == "1")
        tristate = nts::True;
    else if (input.at(1) == "U")
        tristate = nts::Undefined;
    else {
        std::cerr << "Undefined state, please check and retry" << std::endl;
        return true;
    }

    for (nts::IComponent *compPtr : input_component) {
        for (const auto &pair : map) {
            if (pair.second.get() == compPtr) {
                if (pair.first == *input.begin()) {
                    nts::SmartComponent *smartComp = dynamic_cast<nts::SmartComponent*>(pair.second.get());
                    if (smartComp) {
                        smartComp->setState(tristate);
                        return true;
                    } else {
                        throw nts::Nts::Error("Dynamic cast exception.");
                    }
                }
            }
        }
    }
    std::cerr << "No component with this name found." << std::endl;
    return true;
}
